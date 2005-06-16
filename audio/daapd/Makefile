# New ports collection makefile for:	daapd
# Date created:				19 October 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	daapd
PORTVERSION=	0.2.3d
CATEGORIES=	audio
MASTER_SITES=	http://www.deleet.de/projekte/daap/daapd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Server for Digital Audio Access Protocol

BUILD_DEPENDS=	${LOCALBASE}/lib/libid3tag.a:${PORTSDIR}/audio/mad \
		${LOCALBASE}/lib/libdaaplib.a:${PORTSDIR}/audio/daaplib \
		${LOCALBASE}/lib/libhttpd-persistent.a:${PORTSDIR}/www/libhttpd-persistent

USE_GMAKE=	yes
USE_REINPLACE=	yes
MAKEFILE=	makefile
ALL_TARGET=	daapd
USE_RC_SUBR=	yes

MAN8=		daapd.8

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

DAAPD_USER=	daapd
DAAPD_GROUP=	daapd

LOGDIR=		/var/log
CACHE=		/var/db/daapd.cache
FILES_SUB=	USER=${DAAPD_USER} GROUP=${DAAPD_GROUP} \
		PREFIX=${PREFIX} LOGDIR=${LOGDIR} DOCSDIR=${DOCSDIR} \
		LOCALBASE=${LOCALBASE} CACHE=${CACHE} RC_SUBR=${RC_SUBR}
MAKE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

OPTIONS+=	HOWL "Use howl for Zeroconf/Rendezvous" on
OPTIONS+=	MPEG4IP "Use mpeg4ip for AAC metadata" on

.include <bsd.port.pre.mk>

.ifdef(WITH_HOWL)
LIB_DEPENDS+=	howl:${PORTSDIR}/net/howl
MAKE_ENV+=	HOWL_ENABLE=1
.endif

.ifdef(WITH_MPEG4IP)
LIB_DEPENDS+=	mp4v2:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2
MAKE_ENV+=	MPEG4_ENABLE=1
.endif

post-patch:
	@${REINPLACE_CMD} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/${MAKEFILE} \
		${WRKSRC}/README \
		${WRKSRC}/daapd.cc \
		${WRKSRC}/daapd.8

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

.include <bsd.port.post.mk>
