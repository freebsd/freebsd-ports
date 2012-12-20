# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hdoc
PORTVERSION=	0.8.3
PORTREVISION=	6
CATEGORIES=	devel haskell
MASTER_SITES=	http://staff.fmi.uni-passau.de/~groessli/hdoc/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	HTML documentation tool for Haskell

LICENSE=	GPLv2

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}

PLIST_FILES=	bin/hdoc
.if !defined(NOPORTDOCS)
PLIST_DIRS=	share/doc/${DISTNAME}
PLIST_FILES+=	share/doc/${DISTNAME}/hdoc.pdf
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
ALL_TARGET=	# empty

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} && \
	  cd ${WRKSRC}/docs && ${INSTALL_DATA} hdoc.pdf ${DOCSDIR}
.endif

post-patch:
	@${REINPLACE_CMD} 's|import List|import Data.List| ; \
		s|import Char|import Data.Char| ; \
		s|import Ratio|import Data.Ratio| ; \
		s|import Monad|import Control.Monad| ; \
		s|import IO|import System.IO.Error| ; \
		s|import Directory|import System.Directory| ; \
		s|import Maybe|import Data.Maybe| ; \
		s|import Array|import Data.Array| ; \
		s|import System[^\.]|import System.Exit|' \
		`${FIND} ${WRKSRC} -name '*.*hs'`

.include <bsd.port.mk>
