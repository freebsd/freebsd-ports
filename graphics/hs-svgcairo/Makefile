# $FreeBSD$

PORTNAME=	svgcairo
PORTVERSION=	0.13.0.3
CATEGORIES=	graphics haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the libsvg-cairo library

LICENSE=	BSD3CLAUSE

USES=		pkgconfig
USE_CABAL=	cairo>=0.13.0.0 glib>=0.13.0.0 mtl text
USE_GNOME=	librsvg2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
