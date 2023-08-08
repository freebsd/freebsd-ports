PORTNAME=		busybee
PORTVERSION=		0.7.0
DISTVERSIONPREFIX=	releases/
CATEGORIES=		devel

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	High-performance messaging layer
WWW=		https://github.com/rescrv/busybee

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS=	libe.so:devel/libe \
		libpo6.so:devel/libpo6

USES=		autoreconf gmake libtool pathfix pkgconfig
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	rescrv
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
