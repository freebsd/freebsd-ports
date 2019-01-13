# $FreeBSD$

PORTNAME=	geodns
PORTVERSION=	2.7.0
CATEGORIES=	dns net ipv6
PKGNAMEPREFIX=	go-

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	DNS server with per-client targeted responses

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	GeoIP>=1.6.12:net/GeoIP
RUN_DEPENDS=	GeoIP>=1.6.12:net/GeoIP

DEPRECATED=     Uses legacy GeoIP 1 format which no longer works; switch to GeoIP 2 where possible
EXPIRATION_DATE=2019-02-15

USES=		go pkgconfig
USE_RC_SUBR=	geodns
USE_GITHUB=	yes

GH_ACCOUNT=	abh
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PORTEXAMPLES=	*.json

USERS=		_geodns
GROUPS=		_geodns

PLIST_SUB=	USER="${USERS}" GROUP="${GROUPS}"
SUB_LIST=	USER="${USERS}" GROUP="${GROUPS}"
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${MKDIR} ${STAGEDIR}/${ETCDIR}
	${INSTALL_PROGRAM} ${WRKDIR}/bin/geodns ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dns/geodns.conf.sample ${STAGEDIR}${PREFIX}/etc

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dns/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
