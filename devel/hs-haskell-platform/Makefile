# $FreeBSD$

PORTNAME=	haskell-platform
PORTVERSION=	2013.2.0.0
# Please note that the port *strictly depends* on certain versions of other
# ports, so revisit the USE_CABAL line on bumping the portrevision.  Thanks!
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The Haskell Platform

LICENSE=	BSD

METAPORT=	yes

USE_CABAL=	async==2.0.1.4_1 \
		attoparsec==0.10.4.0_2 \
		cgi==3001.1.7.5_1,1 \
		fgl==5.4.2.4_6 \
		GLUT==2.4.0.0_1,1 \
		GLURaw==1.3.0.0_1 \
		haskell-src==1.0.1.5_5 \
		hashable==1.1.2.5_1,1 \
		html==1.0.1.2_8 \
		HTTP==4000.2.8_1 \
		HUnit==1.2.5.2_1 \
		mtl==2.1.2_3 \
		network==2.4.1.2_1 \
		OpenGL==2.8.0.0_1,1 \
		OpenGLRaw==1.3.0.0_1 \
		parallel==3.2.0.3_3 \
		parsec==3.1.3_3 \
		primitive==0.5.0.1_3 \
		QuickCheck==2.6_1 \
		random==1.0.1.1_5 \
		regex-base==0.93.2_8 \
		regex-compat==0.95.1_6 \
		regex-posix==0.95.2_3 \
		split==0.2.2_1 \
		stm==2.4.2_1 \
		syb==0.4.0_1 \
		text==0.11.3.1_1 \
		transformers==0.3.0.0_5 \
		vector==0.10.0.1_3 \
		xhtml==3000.2.1_5 \
		zlib==0.5.4.1_1 \
		cabal-install==1.16.0.2_1 \
		alex==3.0.5_1 \
		happy==1.18.10_3

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
