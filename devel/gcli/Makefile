PORTNAME=	gcli
DISTVERSION=	0.9.12-beta
CATEGORIES=	devel net
MASTER_SITES=	https://herrhotzenplotz.de/gcli/releases/gcli-${DISTVERSION}/

MAINTAINER=	fuz@fuz.su
COMMENT=	CLI utility to interact with various Git forges
WWW=		https://gitlab.com/herrhotzenplotz/gcli

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		libtool pkgconfig tar:xz

GNU_CONFIGURE=	yes
TEST_TARGET=	check

.include <bsd.port.mk>
