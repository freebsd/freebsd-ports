# New ports collection makefile for: hs-OpenAL
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	OpenAL
PORTVERSION=	1.4.0.0
CATEGORIES=	audio haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	A Haskell binding to the OpenAL cross-platform 3D audio API

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-StateVar>=1.0.0.0:${PORTSDIR}/devel/hs-StateVar \
		hs-Tensor>=1.0.0.1:${PORTSDIR}/devel/hs-Tensor \
		hs-ObjectName>=1.0.0.0:${PORTSDIR}/devel/hs-ObjectName
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-StateVar>=1.0.0.0:${PORTSDIR}/devel/hs-StateVar \
		hs-Tensor>=1.0.0.1:${PORTSDIR}/devel/hs-Tensor \
		hs-ObjectName>=1.0.0.0:${PORTSDIR}/devel/hs-ObjectName
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal

GHC_VERSION=		6.10.4
HSOPENAL_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

EXAMPLESDIR=		${PREFIX}/share/examples/${DISTNAME}
DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}
HSOPENAL_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		HSOPENAL_VERSION=${HSOPENAL_VERSION} \
		HSOPENAL_LIBDIR_REL=${HSOPENAL_LIBDIR_REL}

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
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${HSOPENAL_LIBDIR_REL}/register.sh
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR} && cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
