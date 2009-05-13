# New ports collection makefile for:	Stream
# Date created:				November 26, 2008
# Whom:					Samy Al Bahra <sbahra@kerneled.org>
#
# $FreeBSD$

PORTNAME=	Stream
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/ \
		http://carte.kerneled.org/mirror/
PKGNAMEPREFIX=	hs-

MAINTAINER=	sbahra@kerneled.org
COMMENT=	A Haskell library for manipulating infinite lists

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

CABAL=		${LOCALBASE}/bin/runghc Setup.lhs
GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
SUBDIR=		lib/${PORTNAME}-${PORTVERSION}
PLIST_SUB=	GHC_VERSION="${GHC_VERSION}"		\
		PORTVERSION=${PORTVERSION}		\
		SUBDIR=${SUBDIR}

do-configure:
	cd ${WRKSRC} && ${CABAL} configure --prefix=${PREFIX} --ghc

do-build:
	cd ${WRKSRC} && ${CABAL} build && ${CABAL} register --gen-script

do-install:
	cd ${WRKSRC} && ${CABAL} install
	${INSTALL_SCRIPT} ${WRKSRC}/register.sh ${PREFIX}/${SUBDIR}/register.sh

.include <bsd.port.mk>
