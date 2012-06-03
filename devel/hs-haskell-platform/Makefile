# New ports collection makefile for: haskell-platform
# Date created:        April 23, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	haskell-platform
PORTVERSION=	2012.2.0.0
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The Haskell Platform

LICENSE=	BSD

METAPORT=	yes
USE_CABAL=	cgi==3001.1.7.4_3,1 \
		fgl==5.4.2.4_1 \
		GLUT==2.1.2.1_3,1 \
		haskell-src==1.0.1.5 \
		html==1.0.1.2_3 \
		HTTP==4000.2.3 \
		HUnit==1.2.4.2_1 \
		mtl==2.1.1 \
		network==2.3.0.13 \
		OpenGL==2.2.3.1,1 \
		parallel==3.2.0.2 \
		parsec==3.1.2 \
		QuickCheck==2.4.2 \
		random==1.0.1.1 \
		regex-base==0.93.2_3 \
		regex-compat==0.95.1_1 \
		regex-posix==0.95.1_1 \
		stm==2.3 \
		syb==0.3.6.1 \
		text=0.11.2.0 \
		transformers==0.3.0.0 \
		xhtml==3000.2.1 \
		zlib==0.5.3.3 \
		cabal-install==0.14.0 \
		alex==3.0.1 \
		happy==1.18.9

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
