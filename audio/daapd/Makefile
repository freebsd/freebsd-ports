# New ports collection makefile for:	daapd
# Date created:				19 October 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	daapd
PORTVERSION=	0.2.1d
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.deleet.de/projekte/daap/daapd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lars@thegler.dk
COMMENT=	Server for Digital Audio Access Protocol

BUILD_DEPENDS=	${LOCALBASE}/lib/libid3tag.a:${PORTSDIR}/audio/mad \
		${LOCALBASE}/lib/libdaaplib.a:${PORTSDIR}/audio/daaplib \
		${LOCALBASE}/lib/libhttpd-persistent.a:${PORTSDIR}/www/libhttpd-persistent

USE_GMAKE=	yes
USE_REINPLACE=	yes
MAKEFILE=	makefile
ALL_TARGET=	daapd

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

DAAPD_USER=	daapd
DAAPD_GROUP=	daapd

LOGDIR=		/var/log
FILES_SUB=	USER=${DAAPD_USER} GROUP=${DAAPD_GROUP} \
		PREFIX=${PREFIX} LOGDIR=${LOGDIR} DOCSDIR=${DOCSDIR} \
		LOCALBASE=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/${MAKEFILE}

pre-install:
	@${SED} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${PKGDIR}/pkg-install > ${PKGINSTALL}
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${INSTALL_DATA} ${WRKSRC}/daapd-example.conf ${PREFIX}/etc/daapd.conf.sample
	@${SED} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/daapd.sh > ${WRKDIR}/daapd.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/daapd.sh ${PREFIX}/etc/rc.d/daapd.sh
	@${SED} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${PKGDIR}/pkg-deinstall > ${PKGDEINSTALL}
	@${SED} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${PKGDIR}/pkg-message > ${PKGMESSAGE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
