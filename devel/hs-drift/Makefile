# New ports collection makefile for:	drift
# Date created:				13 August 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	drift
PORTVERSION=	2.2.3
PORTREVISION=	6
CATEGORIES=	devel haskell
MASTER_SITES=	http://repetae.net/computer/haskell/DrIFT/drop/
PKGNAMEPREFIX=	hs-
DISTNAME=	DrIFT-${PORTVERSION}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A type sensitive preprocessor for Haskell

OPTIONS_SINGLE=			COMPILER
OPTIONS_SINGLE_COMPILER=	NHC98 GHC
OPTIONS_DEFAULT=		GHC

NHC98_DESC=	Build with NHC98
GHC_DESC=	Build with GHC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGHC}
BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-random>=0:${PORTSDIR}/devel/hs-random
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

CONFIGURE_ARGS+=	--with-hc=ghc
.endif

.if ${PORT_OPTIONS:MNHC98}
BUILD_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
BROKEN=		Does not build

CONFIGURE_ARGS+=	--with-hc=nhc98
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

INFO=	drift
PLIST_FILES=	bin/DrIFT bin/drift-ghc

.if ${PORT_OPTIONS:MGHC}
post-patch:
	@${REINPLACE_CMD} 's|import List|import Data.List| ; \
		s|import Char|import Data.Char| ; \
		s|import Monad|import Control.Monad| ; \
		s|import IO|import System.IO.Error| ; \
		s|import Directory|import System.Directory| ; \
		s|import Maybe|import Data.Maybe| ; \
		s|import Array|import Data.Array| ; \
		s|import Time|import System.Time| ; \
		s|import Random|import System.Random| ; \
		s|import System[^\.]|import System.Exit|' \
		`${FIND} ${WRKSRC} -name '*.*hs'`
.endif

.include <bsd.port.mk>
