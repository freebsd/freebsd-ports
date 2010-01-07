# New ports collection makefile for: hs-uuagc
# Date created:        February 27 2008
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	uuagc
PORTVERSION=	0.9.12
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	Attribute Grammar System of Universiteit Utrecht

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-uulib>=0.9.5:${PORTSDIR}/devel/hs-uulib
LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4

GHC_VERSION=	6.10.4
UUAGC_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}
UUAGC_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		UUAGC_VERSION=${UUAGC_VERSION} \
		UUAGC_LIBDIR_REL=${UUAGC_LIBDIR_REL}

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
	             && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${UUAGC_LIBDIR_REL}/register.sh

post-install:
	${STRIP_CMD} ${PREFIX}/bin/uuagc
	${CHMOD} ${BINMODE} ${PREFIX}/bin/uuagc
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
