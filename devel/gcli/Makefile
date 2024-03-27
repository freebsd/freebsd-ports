PORTNAME=	gcli
DISTVERSION=	2.3.0
CATEGORIES=	devel net
MASTER_SITES=	https://herrhotzenplotz.de/gcli/releases/gcli-${DISTVERSION}/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	CLI utility to interact with various Git forges
WWW=		https://herrhotzenplotz.de/gcli/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl
TEST_DEPENDS=	kyua:devel/kyua

USES=		libtool pathfix pkgconfig tar:xz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
TEST_TARGET=	check

OPTIONS_DEFINE=	TEST
TEST_LIB_DEPENDS=	libatf-c.so:devel/atf

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgcli.so

.include <bsd.port.mk>
