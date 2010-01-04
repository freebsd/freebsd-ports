# New ports collection makefile for: hs-hint
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hint
PORTVERSION=	0.3.2.1
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	Runtime Haskell interpreter (GHC API wrapper)

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-ghc-paths>=0.1.0.5:${PORTSDIR}/devel/hs-ghc-paths \
		hs-utf8-string-ghc>=0.3:${PORTSDIR}/devel/hs-utf8-string-ghc \
		hs-MonadCatchIO-mtl>=0.2:${PORTSDIR}/devel/hs-MonadCatchIO-mtl \
		hs-ghc-mtl>=1.0.1.0:${PORTSDIR}/devel/hs-ghc-mtl
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-ghc-paths>=0.1.0.5:${PORTSDIR}/devel/hs-ghc-paths \
		hs-utf8-string-ghc>=0.3:${PORTSDIR}/devel/hs-utf8-string-ghc \
		hs-MonadCatchIO-mtl>=0.2:${PORTSDIR}/devel/hs-MonadCatchIO-mtl \
		hs-ghc-mtl>=1.0.1.0:${PORTSDIR}/devel/hs-ghc-mtl

GHC_VERSION=	6.10.4
HINT_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

EXAMPLESDIR=		${PREFIX}/share/examples/${DISTNAME}
PORTEXAMPLES=	*

DATADIR=		${PREFIX}/share/${DISTNAME}
PORTDATA=	*

DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}
HINT_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		HINT_VERSION=${HINT_VERSION} \
		HINT_LIBDIR_REL=${HINT_LIBDIR_REL}

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
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${HINT_LIBDIR_REL}/register.sh
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR} && ${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DATADIR} \
			     && ${INSTALL_DATA} ${WRKSRC}/Changes ${DATADIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR} && cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
