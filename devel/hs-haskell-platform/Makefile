# $FreeBSD$

PORTNAME=	haskell-platform
PORTVERSION=	2013.2.0.0
# Please note that the port *strictly depends* on certain versions of other
# ports, so revisit the USE_CABAL line on bumping the portrevision.  Thanks!
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The Haskell Platform

LICENSE=	BSD

METAPORT=	yes

USE_CABAL=	async==2.0.1.4_2 \
		attoparsec==0.10.4.0_3 \
		cgi==3001.1.7.5_2,1 \
		fgl==5.4.2.4_7 \
		GLUT==2.4.0.0_2,1 \
		GLURaw==1.3.0.0_2 \
		haskell-src==1.0.1.5_6 \
		hashable==1.1.2.5_2,1 \
		html==1.0.1.2_9 \
		HTTP==4000.2.8_2 \
		HUnit==1.2.5.2_2 \
		mtl==2.1.2_4 \
		network==2.4.1.2_2 \
		OpenGL==2.8.0.0_2,1 \
		OpenGLRaw==1.3.0.0_2 \
		parallel==3.2.0.3_4 \
		parsec==3.1.3_4 \
		primitive==0.5.0.1_4 \
		QuickCheck==2.6_2 \
		random==1.0.1.1_6 \
		regex-base==0.93.2_9 \
		regex-compat==0.95.1_7 \
		regex-posix==0.95.2_4 \
		split==0.2.2_2 \
		stm==2.4.2_2 \
		syb==0.4.0_2 \
		text==0.11.3.1_2 \
		transformers==0.3.0.0_6 \
		vector==0.10.0.1_4 \
		xhtml==3000.2.1_6 \
		zlib==0.5.4.1_2 \
		cabal-install==1.16.0.2_2 \
		alex==3.0.5_2 \
		happy==1.18.10_4

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
