# $FreeBSD$

PORTNAME=	aml
PORTVERSION=	s20200717
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Another Main Loop

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	any1
GH_TAGNAME=	696f0ee

.include <bsd.port.mk>
