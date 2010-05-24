# New ports collection makefile for:	hs-lazysmallcheck-ghc
# Date created:				March 11, 2009
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lazysmallcheck
PORTVERSION=	0.5
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A library for demand-driven testing of Haskell programs

CABAL_SETUP=	Setup.hs

PORTEXAMPLES=		*
INSTALL_PORTEXAMPLES=	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
