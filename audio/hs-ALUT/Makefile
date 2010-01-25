# New ports collection makefile for: hs-ALUT
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ALUT
PORTVERSION=	2.2.0.0
PORTREVISION=	1
CATEGORIES=	audio haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	A Haskell binding for the OpenAL Utility Toolkit

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-StateVar>=1.0.0.0:${PORTSDIR}/devel/hs-StateVar \
		hs-OpenAL>=1.4.0.0:${PORTSDIR}/audio/hs-OpenAL
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-StateVar>=1.0.0.0:${PORTSDIR}/devel/hs-StateVar \
		hs-OpenAL>=1.4.0.0:${PORTSDIR}/audio/hs-OpenAL

GHC_VERSION=	6.10.4
HSALUT_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup
USE_OPENAL=	al alut

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

EXAMPLESDIR=		${PREFIX}/share/examples/${DISTNAME}
DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}
HSALUT_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		HSALUT_VERSION=${HSALUT_VERSION} \
		HSALUT_LIBDIR_REL=${HSALUT_LIBDIR_REL}

PORTEXAMPLES=	*

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
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.hs -o setup -package Cabal \
		     && ${SETENV} CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"\
		     		${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX}
do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${HSALUT_LIBDIR_REL}/register.sh
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR} && cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
