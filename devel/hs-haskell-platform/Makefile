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

USE_CABAL=	async==2.0.1.4_3 \
		attoparsec==0.10.4.0_4 \
		cgi==3001.1.7.5_3,1 \
		fgl==5.4.2.4_8 \
		GLUT==2.4.0.0_3,1 \
		GLURaw==1.3.0.0_3 \
		haskell-src==1.0.1.5_7 \
		hashable==1.1.2.5_3,1 \
		html==1.0.1.2_10 \
		HTTP==4000.2.8_3 \
		HUnit==1.2.5.2_3 \
		mtl==2.1.2_5 \
		network==2.4.1.2_3 \
		OpenGL==2.8.0.0_3,1 \
		OpenGLRaw==1.3.0.0_3 \
		parallel==3.2.0.3_5 \
		parsec==3.1.3_5 \
		primitive==0.5.0.1_5 \
		QuickCheck==2.6_3 \
		random==1.0.1.1_7 \
		regex-base==0.93.2_10 \
		regex-compat==0.95.1_8 \
		regex-posix==0.95.2_5 \
		split==0.2.2_3 \
		stm==2.4.2_3 \
		syb==0.4.0_3 \
		text==0.11.3.1_3 \
		transformers==0.3.0.0_7 \
		vector==0.10.0.1_5 \
		xhtml==3000.2.1_7 \
		zlib==0.5.4.1_3 \
		cabal-install==1.16.0.2_3 \
		alex==3.0.5_3 \
		happy==1.18.10_5

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
