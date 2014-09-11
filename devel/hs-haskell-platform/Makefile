# $FreeBSD$

PORTNAME=	haskell-platform
PORTVERSION=	2014.2.0.0
# Please note that the port *strictly depends* on certain versions of other
# ports, so revisit the USE_CABAL line on bumping the portrevision.  Thanks!
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The Haskell Platform

LICENSE=	BSD3CLAUSE

METAPORT=	yes

USE_CABAL=	async==2.0.1.5 \
		attoparsec==0.10.4.0_6 \
		case-insensitive==1.1.0.3 \
		fgl==5.5.0.1 \
		GLUT==2.5.1.1,1 \
		GLURaw==1.4.0.1 \
		haskell-src==1.0.1.6 \
		hashable==1.2.2.0,1 \
		html==1.0.1.2_12 \
		HTTP==4000.2.10 \
		HUnit==1.2.5.2_5 \
		mtl==2.1.3.1 \
		network==2.4.2.3 \
		OpenGL==2.9.2.0,1 \
		OpenGLRaw==1.5.0.0 \
		parallel==3.2.0.4 \
		parsec==3.1.5 \
		primitive==0.5.2.1 \
		QuickCheck==2.6_5 \
		random==1.0.1.1_9 \
		regex-base==0.93.2_12 \
		regex-compat==0.95.1_10 \
		regex-posix==0.95.2_7 \
		split==0.2.2_5 \
		stm==2.4.2_5 \
		syb==0.4.1 \
		text==1.1.0.0 \
		unordered-containers==0.2.4.0 \
		vector==0.10.9.1 \
		zlib==0.5.4.1_5 \
		cabal-install==1.18.0.5 \
		alex==3.1.3 \
		happy==1.19.4 \
		hscolour==1.20.3_7,1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"

.if ${GHC_VERSION} != 7.8.3
IGNORE=		will not work: GHC ${GHC_VERSION} is not supported
.endif

.include <bsd.port.mk>
