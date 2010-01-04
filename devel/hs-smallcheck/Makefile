# New ports collection makefile for: hs-smallcheck
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	smallcheck
PORTVERSION=	0.4
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	Another lightweight testing library in Haskell

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc

GHC_VERSION=		6.10.4
SMALLCHECK_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

EXAMPLESDIR=	${PREFIX}/share/examples/${DISTNAME}
PORTEXAMPLES=	*

DATADIR=	${PREFIX}/share/${DISTNAME}
PORTDATA=	*

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
SMALLCHECK_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		SMALLCHECK_VERSION=${SMALLCHECK_VERSION} \
		SMALLCHECK_LIBDIR_REL=${SMALLCHECK_LIBDIR_REL}

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
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.hs -o setup -package Cabal
.if !defined(NOPORTDATA)
	cd ${WRKSRC} && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX}
.else
	cd ${WRKSRC} && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX} \
	    --datadir='' --datasubdir='' --docdir='${DOCSDIR}'
.endif

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${SMALLCHECK_LIBDIR_REL}/register.sh
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR} && cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
