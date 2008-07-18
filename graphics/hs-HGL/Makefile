# New ports collection makefile for: hs-HGL-ghc
# Date created:        February 25 2008
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HGL
PORTVERSION=	3.2.0.0
PORTREVISION=	1
CATEGORIES=	graphics haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc

MAINTAINER=	jacula@gmail.com
COMMENT=	A simple graphics library based on X11 or Win32

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-x11-ghc>=1.2.1:${PORTSDIR}/x11/hs-x11-ghc

GHC_VERSION=	6.8.3

CABAL_CMD=	${LOCALBASE}/bin/runghc Setup.hs

HGL_LIBDIR_REL=	lib/${DISTNAME}
DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		HGL_LIBDIR_REL=${HGL_LIBDIR_REL}

.if defined(NOPORTDOCS)
PLIST_SUB+=		NOPORTDOCS=""
.else
PLIST_SUB+=		NOPORTDOCS="@comment "
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock \
		HsColour:${PORTSDIR}/print/hs-hscolour

HSCOLOUR_VERSION=	1.9

PORTDOCS=	*
.endif

.SILENT:

do-configure:
	cd ${WRKSRC} && ${CABAL_CMD} configure --ghc --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${CABAL_CMD} build \
		     && ${CABAL_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${CABAL_CMD} haddock --executables --hyperlink-source \
				    --hscolour-css=${LOCALBASE}/share/hscolour-${HSCOLOUR_VERSION}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${CABAL_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${HGL_LIBDIR_REL}/register.sh
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
