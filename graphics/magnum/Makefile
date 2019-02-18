# $FreeBSD$

PORTNAME=	magnum
DISTVERSIONPREFIX=	v
DISTVERSION=	2019.01
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight, modular graphics middleware for games, data visualization

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libCorradeUtility.so:devel/corrade

USES=		cmake compiler:c++14-lang gl
USE_GITHUB=	yes
GH_ACCOUNT=	mosra
GH_TUPLE=	mosra:toolchains:a3e0aff:t/toolchains
USE_GL=		gl
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DLIB_SUFFIX:STRING=""

.include <bsd.port.mk>
