# New ports collection makefile for: hs-hoogle
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hoogle
PORTVERSION=	4.0.7
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	Haskell API Search

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-safe>=0.2:${PORTSDIR}/devel/hs-safe \
		hs-uniplate>=1.2.0.3:${PORTSDIR}/devel/hs-uniplate
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-safe>=0.2:${PORTSDIR}/devel/hs-safe \
		hs-uniplate>=1.2.0.3:${PORTSDIR}/devel/hs-uniplate
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

GHC_VERSION=	6.10.4
HOOGLE_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DATADIR=		${PREFIX}/share/${DISTNAME}
PORTDATA=	*

DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}
HOOGLE_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		HOOGLE_VERSION=${HOOGLE_VERSION} \
		HOOGLE_LIBDIR_REL=${HOOGLE_LIBDIR_REL}

.if defined(NOPORTDOCS)
PLIST_SUB+=		NOPORTDOCS=""
.else
PLIST_SUB+=		NOPORTDOCS="@comment "
.endif

.if !defined(NOPORTDOCS)

PORT_HADDOCK!=	(cd  ${.CURDIR}/../../lang/ghc && ${MAKE} -V PORT_HADDOCK)
.if !empty(PORT_HADDOCK:M?0)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
.endif
BUILD_DEPENDS+=	HsColour:${PORTSDIR}/print/hs-hscolour

HSCOLOUR_VERSION=	1.15
HSCOLOUR_DATADIR=	${PREFIX}/share/hscolour-${HSCOLOUR_VERSION}

PORTDOCS=	*
.endif

.SILENT:

do-configure:
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.hs -o setup -package Cabal
.if !defined(NOPORTDATA)
	cd ${WRKSRC} && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX}
.else
	cd ${WRKSRC} && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX} \
	    --datadir='' --datasubdir='' --docdir='${DOCSDIR}'
.endif

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --executables --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR} && ${INSTALL_DATA} ${WRKSRC}/README.txt ${DATADIR}
.endif

.include <bsd.port.mk>
