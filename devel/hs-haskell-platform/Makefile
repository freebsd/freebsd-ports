# New ports collection makefile for: haskell-platform
# Date created:        April 23, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	haskell-platform
PORTVERSION=	2011.4.0.0
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The Haskell Platform

LICENSE=	BSD

METAPORT=	yes
USE_CABAL=	cgi==3001.1.7.4_2,1 \
		fgl==5.4.2.4 \
		GLUT==2.1.2.1_2,1 \
		haskell-src==1.0.1.4_2 \
		html==1.0.1.2_2 \
		HUnit==1.2.4.2 \
		mtl==2.0.1.0_2 \
		network==2.3.0.5 \
		OpenGL==2.2.3.0_2,1 \
		parallel==3.1.0.1_2 \
		parsec==3.1.1_2 \
		QuickCheck==2.4.1.1 \
		regex-base==0.93.2_2 \
		regex-compat==0.95.1 \
		regex-posix==0.95.1 \
		stm==2.2.0.1_2 \
		syb==0.3.3 \
		xhtml==3000.2.0.4 \
		zlib==0.5.3.1_2 \
		HTTP==4000.1.2 \
		deepseq==1.1.0.2_2 \
		text=0.11.1.5 \
		transformers==0.2.2.0_2 \
		cabal-install==0.10.2_1 \
		alex==2.3.5_1 \
		happy==1.18.6_1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
