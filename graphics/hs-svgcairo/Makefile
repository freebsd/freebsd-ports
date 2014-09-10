# $FreeBSD$

PORTNAME=	svgcairo
PORTVERSION=	0.12.5.2
PORTREVISION=	1
CATEGORIES=	graphics haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the libsvg-cairo library

LICENSE=	BSD3CLAUSE

USES=		pkgconfig
USE_CABAL=	cairo>=0.12.5.0 glib>=0.12.5.0 mtl
USE_GNOME=	librsvg2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
