# New ports collection makefile for: hs-reactive
# Date created:        January 07 2010
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	reactive
PORTVERSION=	0.11.4
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	Push-pull functional reactive programming

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-category-extras>=0.53.5:${PORTSDIR}/math/hs-category-extras \
		hs-checkers>=0.2.3:${PORTSDIR}/devel/hs-checkers \
		hs-QuickCheck>=2.1.0.2:${PORTSDIR}/devel/hs-QuickCheck \
		hs-Stream>=0.3.1:${PORTSDIR}/devel/hs-Stream \
		hs-TypeCompose>=0.6.3:${PORTSDIR}/devel/hs-TypeCompose \
		hs-unamb>=0.1.5:${PORTSDIR}/devel/hs-unamb \
		hs-vector-space>=0.5:${PORTSDIR}/math/hs-vector-space
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-category-extras>=0.53.5:${PORTSDIR}/math/hs-category-extras \
		hs-checkers>=0.2.3:${PORTSDIR}/devel/hs-checkers \
		hs-QuickCheck>=2.1.0.2:${PORTSDIR}/devel/hs-QuickCheck \
		hs-Stream>=0.3.1:${PORTSDIR}/devel/hs-Stream \
		hs-TypeCompose>=0.6.3:${PORTSDIR}/devel/hs-TypeCompose \
		hs-unamb>=0.1.5:${PORTSDIR}/devel/hs-unamb \
		hs-vector-space>=0.5:${PORTSDIR}/math/hs-vector-space

GHC_VERSION=		6.10.4
REACTIVE_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}
REACTIVE_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		REACTIVE_VERSION=${REACTIVE_VERSION} \
		REACTIVE_LIBDIR_REL=${REACTIVE_LIBDIR_REL}

.if defined(NOPORTDOCS)
PLIST_SUB+=	NOPORTDOCS=""
.else
PLIST_SUB+=	NOPORTDOCS="@comment "
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
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.lhs -o setup -package Cabal \
		     && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${REACTIVE_LIBDIR_REL}/register.sh

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
