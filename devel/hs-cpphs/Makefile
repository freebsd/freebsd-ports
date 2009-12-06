# New ports collection makefile for:	cpphs
# Date created:		14 June 2004
# Whom:			obraun@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cpphs
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.cs.york.ac.uk/fp/cpphs/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A simplified re-implementation of cpp in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

GHC_VERSION=	6.10.4
CPPHS_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DATADIR=	${PREFIX}/share/${DISTNAME}
DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
CPPHS_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		CPPHS_VERSION=${CPPHS_VERSION} \
		CPPHS_LIBDIR_REL=${CPPHS_LIBDIR_REL}

MAN1=	cpphs.1

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
		     && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source --executables \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${CPPHS_LIBDIR_REL}/register.sh
	@${INSTALL_MAN} ${WRKSRC}/docs/cpphs.1 ${PREFIX}/man/man1
	@${MKDIR} ${DATADIR} && ${INSTALL_DATA} ${WRKSRC}/docs/index.html ${DATADIR} \
			     && ${INSTALL_DATA} ${WRKSRC}/docs/design ${DATADIR}

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
