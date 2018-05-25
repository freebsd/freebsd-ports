# $FreeBSD$

PORTNAME=	graphviz
PORTVERSION=	2999.19.0.0
PORTREVISION=	1
CATEGORIES=	graphics haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	This library provides bindings for the Dot language used by the Graphviz

LICENSE=	BSD3CLAUSE

USES=		pkgconfig
USE_CABAL=	colour dlist fgl polyparse temporary wl-pprint-text

IGNORE=		Doesn't build with recent GHC version

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libxdot.pc:graphics/graphviz

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
