PORTNAME=	gcli
DISTVERSION=	0.9.9-beta
CATEGORIES=	devel net
MASTER_SITES=	https://herrhotzenplotz.de/gcli/releases/gcli-${DISTVERSION}/

MAINTAINER=	fuz@fuz.su
COMMENT=	CLI utility to interact with various Git forges
WWW=		https://gitlab.com/herrhotzenplotz/gcli

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		pkgconfig tar:xz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gcli

.include <bsd.port.mk>
