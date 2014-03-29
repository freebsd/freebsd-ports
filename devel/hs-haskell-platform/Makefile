# $FreeBSD$

PORTNAME=	haskell-platform
PORTVERSION=	2013.2.0.0
# Please note that the port *strictly depends* on certain versions of other
# ports, so revisit the USE_CABAL line on bumping the portrevision.  Thanks!
PORTREVISION=	4
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The Haskell Platform

LICENSE=	BSD

METAPORT=	yes

USE_CABAL=	async==2.0.1.4_4 \
		attoparsec==0.10.4.0_5 \
		cgi==3001.1.7.5_4,1 \
		fgl==5.4.2.4_9 \
		GLUT==2.4.0.0_4,1 \
		GLURaw==1.3.0.0_4 \
		haskell-src==1.0.1.5_8 \
		hashable==1.1.2.5_4,1 \
		html==1.0.1.2_11 \
		HTTP==4000.2.8_4 \
		HUnit==1.2.5.2_4 \
		mtl==2.1.2_6 \
		network==2.4.1.2_4 \
		OpenGL==2.8.0.0_4,1 \
		OpenGLRaw==1.3.0.0_4 \
		parallel==3.2.0.3_6 \
		parsec==3.1.3_6 \
		primitive==0.5.0.1_6 \
		QuickCheck==2.6_4 \
		random==1.0.1.1_8 \
		regex-base==0.93.2_11 \
		regex-compat==0.95.1_9 \
		regex-posix==0.95.2_6 \
		split==0.2.2_4 \
		stm==2.4.2_4 \
		syb==0.4.0_4 \
		text==0.11.3.1_4 \
		transformers==0.3.0.0_8 \
		vector==0.10.0.1_6 \
		xhtml==3000.2.1_8 \
		zlib==0.5.4.1_4 \
		cabal-install==1.16.0.2_4 \
		alex==3.0.5_4 \
		happy==1.18.10_6

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
