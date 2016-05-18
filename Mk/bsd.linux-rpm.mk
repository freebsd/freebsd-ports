#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

# Variables:
# LINUX_DIST		- Will be used to set some dist-specific presets.
#					  Valid values: fedora
# LINUX_DIST_VER	- Use depends upon the dist-specific presets.
#					  Valid values for "fedora": all version numbers
#					  e.g. 10 for fedora 10
#					  Valid values for "centos": all version numbers
#					  e.g. 6.7 for centos 6.7
#					  This is used to set MASTER_SITE_{,SRC_}SUBDIR
#					  if it isn't already set.
# MASTER_SITE_SRC_SUBDIR
#					- The subdir for the src RPM's.
# DISTFILES			- For simple cases this will be set automatically
#					  based upon the DISTNAME.
# SRC_DISTFILES		- Variable which contains the corresponding src RPM's.
#					  If there's no corresponding src RPM, it has to be
#					  set to the empty value (SRC_DISTFILES=	"").
# AUTOMATIC_PLIST	- Generate a dynamic plist (please have a look at the
#					  porters handbook section which talks about plists.
#					  This feature is reserved for rare cases).
# BRANDELF_DIRS		- A list of directories with executables to brand
#					  as a linux executable. The directories has to not
#					  contain libraries.
# BRANDELF_FILES	- A list of files to brand as a linux executable in
#					  case BRANDELF_DIRS can't be used.

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	emulation@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm
SRC_SUFX?=		.src.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.	if ${USE_LINUX} == "c6" || ${USE_LINUX} == "c6_64" || ${USE_LINUX} == "yes" # default to CentOS
# Do not build CentOS 6 ports if overridden by f10
.		if defined(OVERRIDE_LINUX_NONBASE_PORTS) && ${OVERRIDE_LINUX_NONBASE_PORTS} == "f10"
IGNORE=	This port requires CentOS ${LINUX_DIST_VER}. Please remove OVERRIDE_LINUX_NONBASE_PORTS=f10 in /etc/make.conf.
.		endif
.	endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

.if ${USE_LINUX} == "f10"
USE_LINUX?=	"f10"
LINUX_DIST=	fedora
LINUX_DIST_VER=	10
.else			# default to CentOS
LINUX_DIST=	centos
LINUX_DIST_VER=	6.7
.endif

.if defined(LINUX_DIST)
DIST_SUBDIR?=	rpm/${LINUX_RPM_ARCH}/${LINUX_DIST}/${LINUX_DIST_VER}

.	if ${LINUX_DIST} == "fedora"
# we do not want to define MASTER_SITES and MASTER_SITE_* if they are already defined
# ex.: MASTER_SITES=file:///...
.		ifndef MASTER_SITES
MASTER_SITES=		${MASTER_SITE_FEDORA_LINUX}
.			if ${LINUX_DIST_VER} == 10
MASTER_SITE_SUBDIR?=	../releases/${LINUX_DIST_VER}/Everything/${LINUX_RPM_ARCH}/os/Packages \
			../updates/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}
MASTER_SITE_SRC_SUBDIR?=	../releases/${LINUX_DIST_VER}/Everything/source/SRPMS \
				../updates/${LINUX_DIST_VER}/SRPMS
.			else
MASTER_SITE_SUBDIR?=	${LINUX_DIST_VER}/${LINUX_RPM_ARCH}/os/Fedora/RPMS \
			updates/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}
MASTER_SITE_SRC_SUBDIR?=	${LINUX_DIST_VER}/SRPMS \
				updates/${LINUX_DIST_VER}/SRPMS
.			endif
.		endif
.	elif ${LINUX_DIST} == "centos"
MASTER_SITES?=		${MASTER_SITE_CENTOS_LINUX} ${MASTER_SITE_CENTOS_LINUX_UPDATES}
MASTER_SITE_SUBDIR?=	centos/${LINUX_DIST_VER}/os/${LINUX_REPO_ARCH}/Packages/ \
			centos/${LINUX_DIST_VER}/updates/${LINUX_REPO_ARCH}/Packages/
.		if ${LINUX_DIST_VER} == "5" #needed for Qt...
LINUX_RPM_ARCH=		i386
MASTER_SITE_SUBDIR=	centos/5/os/i386/Packages/
.		endif
.		if defined(PACKAGE_BUILDING)
_SRC_GROUP=:SOURCE
MASTER_SITES+=  http://vault.centos.org/%SUBDIR%/:SOURCE
MASTER_SITE_SUBDIR+=	${LINUX_DIST_VER}/os/Source/SPackages/:SOURCE
.		endif
.	endif
.endif

PKGNAMEPREFIX?=			linux-${USE_LINUX}-

# DISTFILES and SRC_DISTFILES assume that there is only one bindist
# and one src file.
# Please, define them in the Makefile of the port in case this assumption
# is not true.

DISTVERSION=	${PORTVERSION}-${RPMVERSION}
DISTNAME?=		${PORTNAME}-${DISTVERSION}
DISTFILES?=		${DISTNAME}${EXTRACT_SUFX}
BIN_DISTFILES:=		${DISTFILES} ${LIB_DISTFILES}
SRC_DISTFILES?=		${DISTNAME}${SRC_SUFX}${_SRC_GROUP}
EXTRACT_ONLY?=		${BIN_DISTFILES:C/:[^:]+$//}
WRKSRC:=		${WRKSRC:S/-${RPMVERSION}$//}

# Define files to install.
# Ports can want to install 32bit things only (if OVERRIDE_LINUX_NONBASE_PORTS) is off,
# they can want to install both 32bit and 64bit things of only one package,
# or they can want to install a 64bit only binary and e.g. 32/64bit libraries.

# The following glue is supposed to handle this.
# FIXME: Sensibly refactor this part, it looks like spaghetti.

.   if defined(OVERRIDE_LINUX_NONBASE_PORTS) && ${OVERRIDE_LINUX_NONBASE_PORTS} == "c6_64"
_32BIT_LINUX_RPM_ARCH=  i686
.       if ${DISTFILES} == ${DISTNAME}${EXTRACT_SUFX} && ${USE_LINUX_RPM} != "nolib"
_32BIT_LIB_DISTFILES:=   ${DISTFILES:S/${LINUX_RPM_ARCH}/${_32BIT_LINUX_RPM_ARCH}/g}
.       elif defined(LIB_DISTFILES)
_32BIT_LIB_DISTFILES=   ${LIB_DISTFILES:S/${LINUX_RPM_ARCH}/${_32BIT_LINUX_RPM_ARCH}/g}
.       endif

BIN_DISTFILES:=         ${BIN_DISTFILES} ${_32BIT_LIB_DISTFILES}
DISTFILES+=             ${_32BIT_LIB_DISTFILES}
.   endif
DISTFILES+=             ${LIB_DISTFILES}


.	if defined(PACKAGE_BUILDING)
DISTFILES+=		${SRC_DISTFILES}
MASTER_SITE_SUBDIR+=	${MASTER_SITE_SRC_SUBDIR}
ALWAYS_KEEP_DISTFILES=	yes
.	endif

.if !defined(USE_LINUX_RPM_BAD_PERMS)
EXTRACT_CMD?=			${TAR}
EXTRACT_BEFORE_ARGS?=	--no-same-permissions --no-same-owner -xf
EXTRACT_AFTER_ARGS?=
.else
EXTRACT_DEPENDS+=	rpm2archive:archivers/rpm4
EXTRACT_CMD?=	rpm2archive
EXTRACT_BEFORE_ARGS?=	<
EXTRACT_AFTER_ARGS?=	| ${TAR} xf - --no-same-permissions --no-same-owner
.endif

DISTINFO_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

BRANDELF_DIRS?=
BRANDELF_FILES?=

# For ports that define PORTDOCS, be sure not to install
# documentation if NOPORTDOCS is defined
.  if defined(PORTDOCS) && defined(NOPORTDOCS)
pre-patch: linux-rpm-clean-portdocs

.		if !target(linux-rpm-clean-portdocs)
linux-rpm-clean-portdocs:
.			for x in ${PORTDOCS}
	@${RM} -f ${WRKSRC}/${DOCSDIR_REL}/${x}
.			endfor
	@${RMDIR} ${WRKSRC}/${DOCSDIR_REL}
.		endif
.  endif

.  if ${USE_LINUX} != "f10"
PLIST?=		${MASTERDIR}/pkg-plist.${LINUX_RPM_ARCH}
.  endif

.  if defined(AUTOMATIC_PLIST)

.	if ${USE_LINUX} == "f10"
_LINUX_BASE_SUFFIX=		f10
.	elif ${USE_LINUX} == "c6" || ${USE_LINUX} == "yes"
_LINUX_BASE_SUFFIX=		c6
.	elif ${USE_LINUX} == "c6_64"
_LINUX_BASE_SUFFIX=		c6
.	else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"f10\", \"c6\", and \"c6_64\"
.  endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

.  if !target(linux-rpm-generate-plist)
linux-rpm-generate-plist:
	cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST}
.	endif
.  endif

.  if !target(do-install)
do-install:
.	if ${BRANDELF_DIRS}
		@cd ${WRKSRC} && ${FIND} ${BRANDELF_DIRS} -type f -print0 \
		| ${XARGS} -0 ${FILE} | ${GREP} ELF | ${CUT} -d : -f 1 \
		| ${XARGS} ${BRANDELF} -t Linux
.	endif
.	if ${BRANDELF_FILES}
		@cd ${WRKSRC} && ${BRANDELF} -t Linux ${BRANDELF_FILES}
.	endif
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${STAGEDIR}${PREFIX}
.  endif
.endif
