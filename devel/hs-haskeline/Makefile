# New ports collection makefile for: hs-haskeline
# Date created:        July 09 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$

PORTNAME=	haskeline
PORTVERSION=	0.6.1.6
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	A command-line interface for user input, written in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-utf8-string-ghc>=0.3:${PORTSDIR}/devel/hs-utf8-string-ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-utf8-string-ghc>=0.3:${PORTSDIR}/devel/hs-utf8-string-ghc

GHC_VERSION=		6.10.4
HASKELINE_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
HASKELINE_LIBDIR_REL=	lib/${DISTNAME}

USE_ICONV=	yes

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		HASKELINE_VERSION=${HASKELINE_VERSION} \
		HASKELINE_LIBDIR_REL=${HASKELINE_LIBDIR_REL}

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
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.hs -o setup -package Cabal \
		     && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX} \
		     --extra-include-dirs="${LOCALBASE}/include" --extra-lib-dirs="${LOCALBASE}/lib"

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${HASKELINE_LIBDIR_REL}/register.sh

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
