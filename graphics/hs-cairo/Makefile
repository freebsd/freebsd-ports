# $FreeBSD$

PORTNAME=	cairo
PORTVERSION=	0.12.4
PORTREVISION=	5
CATEGORIES=	graphics haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the Cairo library

LICENSE=	BSD

USES=		pkgconfig
USE_CABAL=	gtk2hs-buildtools mtl

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/cairo-pdf.pc:${PORTSDIR}/graphics/cairo

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
