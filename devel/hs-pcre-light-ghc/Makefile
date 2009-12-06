# New ports collection makefile for:	pcre-light
# Date created:				December 16, 2008
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pcre-light
PORTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A lightweight Haskell regex library compatible with Perl 5

BUILD_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc

GHC_VERSION=		6.10.4
PCRELIGHT_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}
PCRELIGHT_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		PCRELIGHT_VERSION=${PCRELIGHT_VERSION} \
		PCRELIGHT_LIBDIR_REL=${PCRELIGHT_LIBDIR_REL}

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
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.lhs -o setup -package Cabal \
		     && ${SETUP_CMD} configure --haddock-options=-w \
		     			       --extra-include-dirs=${LOCALBASE}/include \
					       --extra-lib-dirs=${LOCALBASE}/lib  --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${PCRELIGHT_LIBDIR_REL}/register.sh

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
