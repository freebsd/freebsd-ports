# $FreeBSD$

PORTNAME=	threadscope
PORTVERSION=	0.2.8
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Graphical tool for profiling parallel Haskell programs

LICENSE=	BSD3CLAUSE

USE_CABAL=	cairo ghc-events glib gtk mtl pango

EXECUTABLE=	threadscope

STANDALONE=	yes

IGNORE=		Doesn't build with recent GHC version

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
