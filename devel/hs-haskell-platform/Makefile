# New ports collection makefile for: haskell-platform
# Date created:        April 23, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	haskell-platform
PORTVERSION=	2011.2.0.1
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The Haskell Platform

LICENSE=	BSD

METAPORT=	yes
USE_CABAL=	cgi==3001.1.7.4_1,1 \
		fgl==5.4.2.3_2 \
		GLUT==2.1.2.1_1,1 \
		haskell-src==1.0.1.4_1 \
		html==1.0.1.2_1 \
		HUnit==1.2.2.3_1 \
		mtl==2.0.1.0_1 \
		network==2.3.0.2_1 \
		OpenGL==2.2.3.0_1,1 \
		parallel==3.1.0.1_1 \
		parsec==3.1.1_1 \
		QuickCheck==2.4.0.1_1 \
		regex-base==0.93.2_1 \
		regex-compat==0.93.1_1 \
		regex-posix==0.94.4_1 \
		stm==2.2.0.1_1 \
		syb==0.3_1 \
		xhtml==3000.2.0.1_1 \
		zlib==0.5.3.1_1 \
		HTTP==4000.1.1_1 \
		deepseq==1.1.0.2_1 \
		text=0.11.0.6_1 \
		transformers==0.2.2.0_1 \
		cabal-install==0.10.2 \
		alex==2.3.5 \
		happy==1.18.6

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
