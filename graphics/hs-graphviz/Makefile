# $FreeBSD$

PORTNAME=	graphviz
PORTVERSION=	2999.20.0.2
PORTREVISION=	2
CATEGORIES=	graphics haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	This library provides bindings for the Dot language used by the Graphviz

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USES=		pkgconfig
USE_CABAL=	colour dlist fgl polyparse temporary wl-pprint-text

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libxdot.pc:graphics/graphviz

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
