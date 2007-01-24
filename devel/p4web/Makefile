# New ports collection makefile for:	perforce
# Date created:				3 Mai 2000
# Whom:					sam@inf.enst.fr
#
# $FreeBSD$
#

PORTNAME=	perforce
PORTVERSION=	${VERSION}
PORTREVISION=	${REVISION}
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/pub/perforce/r${PORTVERSION}/bin.${PLATFORM}/ \
		http://filehost.perforce.com/perforce/r${PORTVERSION}/bin.${PLATFORM}/
EXTRACT_SUFX=
DISTFILES=	${BIN_FILES} ${SBIN_FILES}
EXTRACT_ONLY=	# none

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perforce client and server

ONLY_FOR_ARCHS=	i386 amd64 alpha
DIST_SUBDIR=	perforce/${VERSION}/${ARCH}
MD5_FILE=	${MASTERDIR}/distinfo.${PLATFORM}

#
# This is a kludge.  I don't know a better way to set PORTVERSION and
# PORTREVISION such that pkg_version figures out an update is needed
#
ARCH!=	/usr/bin/uname -p
ARCH?=	i386

.if (${ARCH} == i386) || (${ARCH} == amd64)
VERSION=	06.1
REVISION=	6
BIN_FILES=	p4
SBIN_FILES=	p4d p4ftpd p4p p4web
REL_NOTES=	http://www.perforce.com/perforce/doc.061/user/relnotes.txt
.elif ${ARCH} == alpha
VERSION=	99.1
REVISION=	1
PLATFORM=	freebsdaxp
BIN_FILES=	p4
SBIN_FILES=	p4d
REL_NOTES=	http://www.perforce.com/perforce/doc.991/user/relnotes.txt
.else
VERSION=	0
IGNORE=		unsupported platform, sorry
.endif

# End of kludge

RESTRICTED=	Restricted distribution

NO_WRKSUBDIR=	yes

PLIST_FILES=	${BIN_FILES:S+^+bin/+g} \
		${SBIN_FILES:S+^+sbin/+g}

.include <bsd.port.pre.mk>

# Figure out what to install
.if (${ARCH} == i386) || (${ARCH} == amd64)
.if ${OSVERSION} > 504000
.if ${ARCH} == amd64
PLATFORM=	freebsd54x86_64
.else
PLATFORM=	freebsd54x86
.endif
.elif ${OSVERSION} > 400000
PLATFORM=	freebsd4
.else
IGNORE=		only supported on FreeBSD 4.x and greater
.endif
.endif

.if (${ARCH} == amd64) && (${OSVERSION} < 504000)
IGNORE=		amd64 is only supported on FreeBSD 5.4 and later
.endif

# Add compatability dependencies.
.if ${OSVERSION} > 600000
LIB_DEPENDS+=	c_r.5:${PORTSDIR}/misc/compat5x
.elif (${OSVERSION} < 504000) && (${OSVERSION} > 500000)
LIB_DEPENDS+=	c_r.4:${PORTSDIR}/misc/compat4x
.endif

# These variables are all configurable.
PERFORCE_USER?=		p4admin
PERFORCE_UID?=		94
PERFORCE_GROUP?=	p4admin
PERFORCE_GID?=		94
PERFORCE_HOME?=		${LOCALBASE}/perforce
PERFORCE_ROOT?=		${PERFORCE_HOME}/root
PERFORCE_LOGS?=		${PERFORCE_HOME}/logs
PERFORCE_PORT?=		1666
PERFORCE_CACHE?=	${PERFORCE_HOME}/cache
PERFORCE_TARGET?=	perforce:1666

pre-everything::
	@${ECHO} "If the checksums fail, try doing 'make distclean'"
	@${ECHO} "to force getting the latest binaries from Perforce."
	@${ECHO} ""
	@${ECHO} "Read the release notes for this release to determine"
	@${ECHO} "how to migrate the database to the new version.  In"
	@${ECHO} "most instances, it is done automatically.  However,"
	@${ECHO} "sometimes it must be done manually."
	@${ECHO} ""
	@${ECHO} "The release notes for this version are at"
	@${ECHO} ${REL_NOTES}
	@${ECHO} ""
	@${ECHO} "Checkpoint and backup your data before installing!"

do-build:
	${SED}	-e "s,@PERFORCE_ROOT@,${PERFORCE_ROOT},g" \
		-e "s,@PERFORCE_LOGS@,${PERFORCE_LOGS},g" \
		-e "s,@PERFORCE_USER@,${PERFORCE_USER},g" \
		-e "s,@PERFORCE_PORT@,${PERFORCE_PORT},g" \
		-e "s,@PERFORCE_CACHE@,${PERFORCE_CACHE},g" \
		-e "s,@PERFORCE_TARGET@,${PERFORCE_TARGET},g" \
		< ${FILESDIR}/perforce.conf.in > ${WRKSRC}/perforce.conf
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/perforce.sh.in > ${WRKSRC}/perforce.sh

pre-su-install:
	${SETENV} PKG_PREFIX=${PREFIX} \
		PERFORCE_USER=${PERFORCE_USER} \
		PERFORCE_UID=${PERFORCE_UID} \
		PERFORCE_GROUP=${PERFORCE_GROUP} \
		PERFORCE_GID=${PERFORCE_GID} \
		PERFORCE_HOME=${PERFORCE_HOME} \
		PERFORCE_ROOT=${PERFORCE_ROOT} \
		PERFORCE_LOGS=${PERFORCE_LOGS} \
		${SH} ${PKGDIR}/pkg-install ${PORTNAME} PRE-INSTALL

do-install:
.for f in ${BIN_FILES}
	${INSTALL_PROGRAM} ${_DISTDIR}/${f} ${PREFIX}/bin/
.endfor
.for f in ${SBIN_FILES}
	${INSTALL_PROGRAM} ${_DISTDIR}/${f} ${PREFIX}/sbin/
.endfor
	${INSTALL_DATA} ${WRKSRC}/perforce.conf ${PREFIX}/etc/perforce.conf.default; \
	if [ ! -f ${PREFIX}/etc/perforce.conf ]; then \
		${CP} -p ${PREFIX}/etc/perforce.conf.default ${PREFIX}/etc/perforce.conf; \
	fi
	${INSTALL_SCRIPT} ${WRKSRC}/perforce.sh ${PREFIX}/etc/rc.d/

post-install:
	${ECHO_CMD} "@unexec ${RMDIR} ${PERFORCE_ROOT} ${PERFORCE_LOGS} ${PERFORCE_HOME} 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.post.mk>
