# $FreeBSD$

PORTNAME=	threadscope
PORTVERSION=	0.2.11.1
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Graphical tool for profiling parallel Haskell programs

LICENSE=	BSD3CLAUSE

USE_CABAL=	cairo file-embed ghc-events glib gtk mtl pango temporary
EXECUTABLE=	threadscope

STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
