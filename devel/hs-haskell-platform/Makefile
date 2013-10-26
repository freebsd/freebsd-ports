# $FreeBSD$

PORTNAME=	haskell-platform
PORTVERSION=	2013.2.0.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The Haskell Platform

LICENSE=	BSD

METAPORT=	yes

USE_CABAL=	async==2.0.1.4 \
		attoparsec==0.10.4.0_1 \
		cgi==3001.1.7.5,1 \
		fgl==5.4.2.4_5 \
		GLUT==2.4.0.0,1 \
		GLURaw==1.3.0.0 \
		haskell-src==1.0.1.5_4 \
		hashable==1.1.2.5,1 \
		html==1.0.1.2_7 \
		HTTP==4000.2.8 \
		HUnit==1.2.5.2 \
		mtl==2.1.2_2 \
		network==2.4.1.2 \
		OpenGL==2.8.0.0,1 \
		OpenGLRaw==1.3.0.0 \
		parallel==3.2.0.3_2 \
		parsec==3.1.3_2 \
		primitive==0.5.0.1_2 \
		QuickCheck==2.6 \
		random==1.0.1.1_4 \
		regex-base==0.93.2_7 \
		regex-compat==0.95.1_5 \
		regex-posix==0.95.2_2 \
		split==0.2.2 \
		stm==2.4.2 \
		syb==0.4.0 \
		text==0.11.3.1 \
		transformers==0.3.0.0_4 \
		vector==0.10.0.1_2 \
		xhtml==3000.2.1_4 \
		zlib==0.5.4.1 \
		cabal-install==1.16.0.2 \
		alex==3.0.5 \
		happy==1.18.10_2

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
