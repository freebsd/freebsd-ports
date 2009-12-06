# New ports collection makefile for: hs-ghc-paths-docs
# Date created:        July 09 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$

PORTNAME=	ghc-paths
PORTVERSION=	0.1.0.5
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-doc

MAINTAINER=	jacula@gmail.com
COMMENT=	Documentation for ghc-paths

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		HsColour:${PORTSDIR}/print/hs-hscolour
RUN_DEPENDS=	hs-ghc-paths=${PORTVERSION}:${PORTSDIR}/devel/hs-ghc-paths

PORT_HADDOCK!=	(cd  ${.CURDIR}/../../lang/ghc && ${MAKE} -V PORT_HADDOCK)
.if !empty(PORT_HADDOCK:M?0)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
.endif

HSCOLOUR_VERSION=	1.15
HSCOLOUR_DATADIR=	${PREFIX}/share/hscolour-${HSCOLOUR_VERSION}

CABAL_CMD=	runghc Setup.hs

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}

.SILENT:

do-configure:
	cd ${WRKSRC} && ${CABAL_CMD} configure --ghc --haddock-options=-w --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${CABAL_CMD} haddock --executables --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css

do-install:
	${MKDIR} ${DOCSDIR}/html
	cd ${WRKSRC}/dist/doc/html/ghc-paths && ${COPYTREE_SHARE} \* ${DOCSDIR}/html

.include <bsd.port.mk>
