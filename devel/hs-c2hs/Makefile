# New ports collection makefile for:   c2hs
# Date created:        23 August 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c2hs
PORTVERSION=	0.16.0
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	C->Haskell, an Interface Generator for Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-language-c-ghc>=0.3.1.1:${PORTSDIR}/devel/hs-language-c-ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

.include <bsd.port.pre.mk>

GHC_VERSION=	6.8.3

# 'owned' by lang/ghc:
CABALDIR=	${PREFIX}/${SUBDIR}
CABALCMD=	${LOCALBASE}/bin/runghc Setup.hs
SUBDIR=		lib/ghc-${GHC_VERSION}/cabal

PLIST_FILES=	bin/c2hs ${SUBDIR}/${PORTNAME}/C2HS.hs \
			${SUBDIR}/${PORTNAME}/doc/c2hs-${PORTVERSION}/COPYING
PLIST_DIRS=	${SUBDIR}/${PORTNAME}/doc/c2hs-${PORTVERSION} ${SUBDIR}/${PORTNAME}/doc \
			${SUBDIR}/${PORTNAME}

CONFIGURE_ARGS=	--ghc --prefix=${PREFIX} --libdir=${CABALDIR} \
			--datadir=${CABALDIR}/${PORTNAME} \
			--libsubdir='' --datasubdir=''

do-configure:
	cd ${WRKSRC} && ${CABALCMD} configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${CABALCMD} build

do-install:
	cd ${WRKSRC} && ${CABALCMD} install

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/c2hs

.include <bsd.port.post.mk>
