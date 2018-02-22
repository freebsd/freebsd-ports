# $FreeBSD$

PORTNAME=	svgcairo
PORTVERSION=	0.13.1.1
PORTREVISION=	1
CATEGORIES=	graphics haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the libsvg-cairo library

LICENSE=	BSD3CLAUSE

USES=		pkgconfig
USE_CABAL=	cairo glib mtl text
USE_GNOME=	librsvg2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
