PORTNAME=	bstring
DISTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/msteinert/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Improved string processing functionality for the C language
WWW=		https://mike.steinert.ca/bstring/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	checkmk:devel/check

USES=		meson pkgconfig tar:xz
USE_LDCONFIG=	yes

TEST_TARGET=	test

MESON_ARGS=	-Denable-tests=true

.include <bsd.port.mk>
