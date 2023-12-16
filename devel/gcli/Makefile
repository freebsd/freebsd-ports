PORTNAME=	gcli
DISTVERSION=	2.1.0
CATEGORIES=	devel net
MASTER_SITES=	https://herrhotzenplotz.de/gcli/releases/gcli-${DISTVERSION}/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	CLI utility to interact with various Git forges
WWW=		https://herrhotzenplotz.de/gcli/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		libtool pathfix pkgconfig tar:xz

GNU_CONFIGURE=	yes
TEST_TARGET=	check

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgcli.so

.include <bsd.port.mk>
