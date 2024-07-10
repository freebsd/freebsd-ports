PORTNAME=	adsuck
PORTVERSION=	2.3
PORTREVISION=	11
CATEGORIES=	dns
MASTER_SITES=	http://opensource.conformal.com/snapshots/adsuck/ \
		http://philpep.org/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	phil@philpep.org
COMMENT=	DNS relay for ad blocking
WWW=		http://opensource.conformal.com/wiki/Adsuck

DEPRECATED=	Obsolete, no longer relevant
EXPIRATION_DATE=2024-05-31

LICENSE=	ISCL

LIB_DEPENDS+=	libevent.so:devel/libevent \
		libldns.so:dns/ldns

USES=	localbase

USE_RC_SUBR=	adsuck

USERS=	_adsuck
GROUPS=	_adsuck

SUB_FILES+=	pkg-message

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/adsuck ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8.gz ${STAGEDIR}${PREFIX}/share/man/man8

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/files/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
