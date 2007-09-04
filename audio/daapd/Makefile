# New ports collection makefile for:	daapd
# Date created:				19 October 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	daapd
PORTVERSION=	0.2.4b
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.deleet.de/projekte/daap/daapd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Server for Digital Audio Access Protocol

DEPRECATED=	Development stalled, outdated. Does not support newer versions of DAAP protocol.
EXPIRATION_DATE=	2007-11-04

BUILD_DEPENDS=	daaplib>=0.1.1a_2:${PORTSDIR}/audio/daaplib \
		libhttpd-persistent>=1.3h_1:${PORTSDIR}/www/libhttpd-persistent
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	id3tag:${PORTSDIR}/audio/libid3tag

USE_GCC=	3.4+
USE_GMAKE=	yes
MAKEFILE=	makefile
USE_RC_SUBR=	daapd

MAN8=		daapd.8

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

DAAPD_USER=	daapd
DAAPD_GROUP=	daapd

LOGDIR=		/var/log
CACHE=		/var/db/daapd.cache
SUB_LIST+=	USER=${DAAPD_USER} GROUP=${DAAPD_GROUP} \
		LOGDIR=${LOGDIR} CACHE=${CACHE}
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
	@${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/${MAKEFILE} \
		${WRKSRC}/README \
		${WRKSRC}/daapd.cc \
		${WRKSRC}/daapd.8

pre-install:
	@${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${PKGDIR}/pkg-install > ${PKGINSTALL}
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${INSTALL_DATA} ${WRKSRC}/daapd-example.conf ${PREFIX}/etc/daapd.conf.sample
	@${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${PKGDIR}/pkg-deinstall > ${PKGDEINSTALL}
	@${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
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
