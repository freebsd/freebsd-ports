# $FreeBSD$

PORTNAME=	cairo
PORTVERSION=	0.13.5.0
PORTREVISION=	2
CATEGORIES=	graphics haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the Cairo library

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USES=		pkgconfig
USE_CABAL=	gtk2hs-buildtools mtl utf8-string

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/cairo-pdf.pc:graphics/cairo

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
