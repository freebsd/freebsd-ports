# New ports collection makefile for:	haddock
# Date created:				09 May 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haddock
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A documentation tool for Haskell

USE_HACKAGE=	ghc-paths

EXECUTABLE=	haddock

PORTDATA=	*

.include <bsd.port.pre.mk>

.if !defined(SLAVE)
PORT_HADDOCK!=	(cd  ${.CURDIR}/../../lang/ghc && ${MAKE} -V PORT_HADDOCK)
.if ${PORT_HADDOCK} == 11
ECHO_MSG=	${PRINTF} "%b"
IGNORE+=	\n\t The ${LOCALBASE}/bin/haddock executable was already installed\n
IGNORE+=	\t by the lang/ghc port, setting the option WITH_HADDOCK.\n
IGNORE+=	\t You have to reinstall this last one with the right option\n
IGNORE+=	\t WITHOUT_HADDOCK.\n\c
.elif ${PORT_HADDOCK} == 01
ECHO_MSG=	${PRINTF} "%b"
IGNORE+=	\n\t This port depends on the lang/ghc port, which will install\n
IGNORE+=	\t the ${LOCALBASE}/bin/haddock executable, for the WITH_HADDOCK\n
IGNORE+=	\t option was set in it. You have to set the WITHOUT_HADDOCK\n
IGNORE+=	\t options in lang/ghc before to install devel/hs-haddock.\n\c
.endif
.else
GHC_CMD=	ghc
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.post.mk>
