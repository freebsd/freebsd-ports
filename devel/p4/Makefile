# New ports collection makefile for:	perforce
# Date created:				3 Mai 2000
# Whom:					sam@inf.enst.fr
#
# $FreeBSD$
#

PORTNAME=	perforce
PORTVERSION=	${VERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/pub/perforce/r${PORTVERSION}/bin.${PLATFORM}/ \
		ftp://ftp.perforce.com/pub/perforce/r${PORTVERSION}/doc/man/
EXTRACT_SUFX=
DISTFILES=	${BIN_FILES} ${SBIN_FILES} ${MAN1}
DIST_SUBDIR=	perforce/${VERSION}/${ARCH}
EXTRACT_ONLY=	# none

MAINTAINER=	knu@FreeBSD.org

NO_PACKAGE=	Restricted distribution
NO_CDROM=	Restricted distribution
MAN1=		p4.1 p4d.1

NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

# These variables are all configurable.
PERFORCE_USER?=		p4admin
PERFORCE_UID?=		94
PERFORCE_GROUP?=	p4admin
PERFORCE_GID?=		94
PERFORCE_HOME?=		${LOCALBASE}/perforce
PERFORCE_ROOT?=		${PERFORCE_HOME}/root
PERFORCE_LOGS?=		${PERFORCE_HOME}/logs
PERFORCE_PORT?=		1666

.if ${ARCH} == i386
VERSION=	01.1
PLATFORM=	freebsd
BIN_FILES=	p4 p4web
SBIN_FILES=	p4d p4ftpd
.elif ${ARCH} == alpha
VERSION=	99.1
PLATFORM=	freebsdaxp
BIN_FILES=	p4
SBIN_FILES=	p4d
.else
.error "Unsupported platform, sorry."
.endif

do-build:
	${SED} -e "s,@PERFORCE_ROOT@,${PERFORCE_ROOT},g" \
	       -e "s,@PERFORCE_LOGS@,${PERFORCE_LOGS},g" \
	       -e "s,@PERFORCE_USER@,${PERFORCE_USER},g" \
	       -e "s,@PERFORCE_PORT@,${PERFORCE_PORT},g" \
		< ${FILESDIR}/perforce.conf.in > ${WRKSRC}/perforce.conf
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/perforce.sh.in > ${WRKSRC}/perforce.sh

pre-install:
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
.for f in ${MAN1}
	${INSTALL_MAN} ${_DISTDIR}/${f} ${PREFIX}/man/man1/
.endfor
.for f in ${BIN_FILES}
	${INSTALL_PROGRAM} ${_DISTDIR}/${f} ${PREFIX}/bin/
.endfor
.for f in ${SBIN_FILES}
	${INSTALL_PROGRAM} ${_DISTDIR}/${f} ${PREFIX}/sbin/
.endfor

post-install:
.for f in ${BIN_FILES}
	${ECHO} bin/${f} >> ${TMPPLIST}
.endfor
.for f in ${SBIN_FILES}
	${ECHO} sbin/${f} >> ${TMPPLIST}
.endfor
	${ECHO} "@unexec /bin/rmdir ${PERFORCE_ROOT} ${PERFORCE_LOGS} ${PERFORCE_HOME} 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.post.mk>
