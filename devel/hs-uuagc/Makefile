# New ports collection makefile for: hs-uuagc
# Date created:        February 27 2008
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	uuagc
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	Attribute Grammar System of Universiteit Utrecht

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-uulib>=0.9.5:${PORTSDIR}/devel/hs-uulib
LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4

GHC_VERSION=	6.8.3

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}

.SILENT:

do-configure:
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.hs -o setup -package Cabal \
		     && ${SETUP_CMD} configure --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install

post-install:
	${STRIP_CMD} ${PREFIX}/bin/uuagc
	${CHMOD} ${BINMODE} ${PREFIX}/bin/uuagc

.include <bsd.port.mk>
