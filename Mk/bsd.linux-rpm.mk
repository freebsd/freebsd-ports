#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD: /tmp/pcvs/ports/Mk/bsd.linux-rpm.mk,v 1.23 2009-12-13 19:29:34 bsam Exp $
#

# Variables:
# LINUX_DIST		- Will be used to set some dist-specific presets.
#					  Valid values: fedora
# LINUX_DIST_VER	- Use depends upon the dist-specific presets.
#					  Valid values for "fedora": all version numbers
#					  e.g. 3 for fedora core 3, 4 for fedora core 4
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
# _F8_COMPATIBLE_LINUX_BASE_PORTS
#			- A list of linux base ports compatible (may be used) with -f8-
#					  linux infrastructure ports. This variable is ment
#					  to be used at *.mk files

.if !defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Pre_Include)

Linux_RPM_Include_MAINTAINER=	emulation@FreeBSD.org
Linux_RPM_Pre_Include=			bsd.linux-rpm.mk

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm
SRC_SUFX?=		.src.rpm

USE_LINUX?=			yes
USE_LINUX_PREFIX=	yes

NO_WRKSUBDIR=		yes
NO_BUILD=			yes

.  if ${ARCH} == "amd64"
LINUX_RPM_ARCH?=	i386	# the linuxulator does not yet support amd64 code
.  elif ${ARCH} == "powerpc"
LINUX_RPM_ARCH?=	ppc
.  else
LINUX_RPM_ARCH?=	${ARCH}
.  endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_RPM_Post_Include)

Linux_RPM_Post_Include=	bsd.linux-rpm.mk

LINUX_DIST?=		fedora
. if ${OSVERSION} < 800076
LINUX_DIST_VER?=	4
. else
LINUX_DIST_VER?=	10
.   if  !defined(OVERRIDE_LINUX_NONBASE_PORTS) && \
        ${LINUX_DIST_VER} != 10
IGNORE=		bsd.linux-rpm.mk test failed: default package building at OSVERSION>=800076 was changed to linux-f10 ports, please define OVERRIDE_LINUX_NONBASE_PORTS to build other linux infrastructure ports
.   endif
. endif

# linux Fedora 8 infrastructure ports should be used with compat.linux.osrelease=2.6.16,
# linux_base-f8 (or greater) port
.  if ${LINUX_DIST_VER} == 8 || ${LINUX_DIST_VER} == 10
# let's check for apropriate compat.linux.osrelease
.    if (${LINUX_OSRELEASE} != "2.6.16")
IGNORE=		bsd.linux-rpm.mk test failed: the port should be used with compat.linux.osrelease=2.6.16, which is supported at 8-CURRENT and has a limited support at 7-STABLE
.    endif
# the default for OSVERSION < 800076
.    if ${OSVERSION} < 800076
# let's check if an apropriate linux base port is used
.      if ${USE_LINUX} != f8 && ${USE_LINUX} != f9 && ${USE_LINUX} != f10
IGNORE=		bsd.linux-rpm.mk test failed: the port should be used with at least linux_base-f8, please read /usr/ports/UPDATING
.      endif
# let's check if OVERRIDE_LINUX_NONBASE_PORTS is defined
.      ifndef(OVERRIDE_LINUX_NONBASE_PORTS)
IGNORE=		bsd.linux-rpm.mk test failed: the port should be used with defined OVERRIDE_LINUX_NONBASE_PORTS, please read /usr/ports/UPDATING
.      endif
# the default for OSVERSION >= 800076
#.      else
.    endif # ${OSVERSION} < 800076
.  endif

.  if defined(LINUX_DIST)
DIST_SUBDIR?=	rpm/${LINUX_RPM_ARCH}/${LINUX_DIST}/${LINUX_DIST_VER}

.    if ${LINUX_DIST} == "fedora"
# we do not want to define MASTER_SITES and MASTER_SITE_* if they are already defined
# ex.: MASTER_SITES=file:///...
.      ifndef MASTER_SITES
MASTER_SITES=			${MASTER_SITE_FEDORA_LINUX}
.        if ${LINUX_DIST_VER} == 8
MASTER_SITE_SUBDIR?=	../releases/${LINUX_DIST_VER}/Everything/${LINUX_RPM_ARCH}/os/Packages \
			../updates/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}.newkey
MASTER_SITE_SRC_SUBDIR?=	../releases/${LINUX_DIST_VER}/Everything/source/SRPMS \
				../updates/${LINUX_DIST_VER}/SRPMS.newkey
.        elif ${LINUX_DIST_VER} == 10
MASTER_SITE_SUBDIR?=	../releases/${LINUX_DIST_VER}/Everything/${LINUX_RPM_ARCH}/os/Packages \
			../updates/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}
MASTER_SITE_SRC_SUBDIR?=	../releases/${LINUX_DIST_VER}/Everything/source/SRPMS \
				../updates/${LINUX_DIST_VER}/SRPMS
.        else
MASTER_SITE_SUBDIR?=	${LINUX_DIST_VER}/${LINUX_RPM_ARCH}/os/Fedora/RPMS \
			updates/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}
MASTER_SITE_SRC_SUBDIR?=	${LINUX_DIST_VER}/SRPMS \
				updates/${LINUX_DIST_VER}/SRPMS
.        endif
.      endif
.    else
IGNORE=	unknown LINUX_DIST in port Makefile
.    endif
.  endif
PKGNAMEPREFIX?=			linux-

# DISTFILES and SRC_DISTFILES assume that there is only one bindist
# and one src file.
# Please, define them n the Makefile of the port in case this assumption
# is not true.

DISTFILES?=		${DISTNAME}${EXTRACT_SUFX}
BIN_DISTFILES:=		${DISTFILES}
SRC_DISTFILES?=		${DISTNAME}${SRC_SUFX}
EXTRACT_ONLY?=		${BIN_DISTFILES}

.  if defined(PACKAGE_BUILDING)
DISTFILES+=		${SRC_DISTFILES}
MASTER_SITE_SUBDIR+=	${MASTER_SITE_SRC_SUBDIR}
ALWAYS_KEEP_DISTFILES=	yes
.  endif

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_CMD?=			${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

MD5_FILE?=				${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

BRANDELF_DIRS?=
BRANDELF_FILES?=

# For ports that define PORTDOCS, be sure not to install
# documentation if NOPORTDOCS is defined
.  if defined(PORTDOCS) && defined(NOPORTDOCS)
pre-patch: linux-rpm-clean-portdocs

.    if !target(linux-rpm-clean-portdocs)
linux-rpm-clean-portdocs:
.      for x in ${PORTDOCS}
	@${RM} -f ${WRKDIR}/${DOCSDIR_REL}/${x}
.      endfor
	@${RMDIR} ${WRKDIR}/${DOCSDIR_REL}
.    endif
.  endif

.  if defined(AUTOMATIC_PLIST)

.    if ${USE_LINUX} == "fc4" || ${USE_LINUX:L} == "yes"
_LINUX_BASE_SUFFIX=		fc4
.    elif ${USE_LINUX} == "fc6"
_LINUX_BASE_SUFFIX=		fc6
.    elif ${USE_LINUX} == "f7"
_LINUX_BASE_SUFFIX=		f7
.    elif ${USE_LINUX} == "f8"
_LINUX_BASE_SUFFIX=		f8
.    elif ${USE_LINUX} == "f9"
_LINUX_BASE_SUFFIX=		f9
.    elif ${USE_LINUX} == "f10"
_LINUX_BASE_SUFFIX=		f10
.    else
# other linux_base ports do not provide a pkg-plist file
IGNORE=					uses AUTOMATIC_PLIST with an unsupported USE_LINUX, \"${USE_LINUX}\". Supported values are \"yes\", \"fc4\", \"fc6\", \"f7\", \"f8\", \"f9\" and \"f10\"
.    endif

PLIST?=					${WRKDIR}/.PLIST.linux-rpm

pre-install: linux-rpm-generate-plist

.    if !target(linux-rpm-generate-plist)
linux-rpm-generate-plist:
	@cd ${WRKSRC} && \
	${FIND} * ! -type d | ${SORT} > ${PLIST} && \
	${FIND} * -type d | ${SORT} | ${SED} -e 's|^|@dirrm |' > ${PLIST}.dirs
	@${GREP} '^@dirrm' ${PORTSDIR}/emulators/linux_base-${_LINUX_BASE_SUFFIX}/pkg-plist | ${SED} 's:^@dirrmtry:@dirrm:g' | ${SORT} > ${PLIST}.shared-dirs
	@${COMM} -1 -3 ${PLIST}.shared-dirs ${PLIST}.dirs | ${SORT} -r >> ${PLIST}
.    endif
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
	cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	cd ${WRKSRC} && ${FIND} * ! -type d | ${CPIO} -pm -R root:wheel ${PREFIX}
.  endif

.  if !target(new-plist)
new-plist: build
	@${RM} -f ${PLIST}.new
	@cd ${WRKSRC} && \
		${FIND} * ! -type d | ${SORT} > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's|^|@dirrm |' >> ${PLIST}.new; \
	done
.  endif

.endif
