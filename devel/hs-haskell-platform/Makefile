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

USE_CABAL=	async==2.0.1.5_1 \
		attoparsec==0.10.4.0_7 \
		case-insensitive==1.1.0.3_1 \
		fgl==5.5.0.1_1 \
		GLUT==2.5.1.1_1,1 \
		GLURaw==1.4.0.1_1 \
		haskell-src==1.0.1.6_1 \
		hashable==1.2.2.0_1,1 \
		html==1.0.1.2_13 \
		HTTP==4000.2.10_1 \
		HUnit==1.2.5.2_6 \
		mtl==2.1.3.1_1 \
		network==2.4.2.3_1 \
		OpenGL==2.9.2.0_1,1 \
		OpenGLRaw==1.5.0.0_1 \
		parallel==3.2.0.4_1 \
		parsec==3.1.5_1 \
		primitive==0.5.2.1_1 \
		QuickCheck==2.6_6 \
		random==1.0.1.1_10 \
		regex-base==0.93.2_13 \
		regex-compat==0.95.1_11 \
		regex-posix==0.95.2_8 \
		split==0.2.2_6 \
		stm==2.4.2_6 \
		syb==0.4.1_1 \
		text==1.1.0.0_1 \
		unordered-containers==0.2.4.0_1 \
		vector==0.10.9.1_1 \
		zlib==0.5.4.1_6 \
		cabal-install==1.18.0.5_1 \
		alex==3.1.3_1 \
		happy==1.19.4_1 \
		hscolour==1.20.3_8,1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"

.if ${GHC_VERSION} != 7.8.3
IGNORE=		will not work: GHC ${GHC_VERSION} is not supported
.endif

.include <bsd.port.mk>
