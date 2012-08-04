# New ports collection makefile for: haskell-platform
# Date created:        April 23, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	haskell-platform
PORTVERSION=	2012.2.0.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The Haskell Platform

LICENSE=	BSD

METAPORT=	yes
USE_CABAL=	cgi==3001.1.7.4_4,1 \
		fgl==5.4.2.4_2 \
		GLUT==2.1.2.1_5,1 \
		haskell-src==1.0.1.5_1 \
		html==1.0.1.2_4 \
		HTTP==4000.2.3_1 \
		HUnit==1.2.4.2_2 \
		mtl==2.1.1_1 \
		network==2.3.0.13_1 \
		OpenGL==2.2.3.1_2,1 \
		parallel==3.2.0.2_1 \
		parsec==3.1.2_1 \
		QuickCheck==2.4.2_1 \
		random==1.0.1.1_1 \
		regex-base==0.93.2_4 \
		regex-compat==0.95.1_2 \
		regex-posix==0.95.1_2 \
		stm==2.3_1 \
		syb==0.3.6.1_1 \
		text=0.11.2.0_1 \
		transformers==0.3.0.0_1 \
		xhtml==3000.2.1_1 \
		zlib==0.5.3.3_1 \
		cabal-install==0.14.0_1 \
		alex==3.0.1_1 \
		happy==1.18.9_1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
