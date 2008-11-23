# New ports collection makefile for:	hs-utf8-string-ghc
# Date created:		2008-10-21
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	utf8-string
PORTVERSION=	0.3.1.1
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc

MAINTAINER=	wahjava@gmail.com
COMMENT=	Support for reading/writing UTF8 strings for Haskell programs

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

CABALCMD=	${LOCALBASE}/bin/runghc Setup.lhs
CABALDIR=	${PREFIX}/lib/ghc-${GHC_VERSION}/cabal
GHC_VERSION=	6.8.3
SUBDIR=		lib/${PORTNAME}-${PORTVERSION}
PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} \
		PORTVERSION=${PORTVERSION} \
		PORTNAME=${PORTNAME} \
		SUBDIR=lib/ghc-${GHC_VERSION}/cabal
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

CONFIGURE_ARGS=	--ghc --prefix=${PREFIX} --libdir=${CABALDIR} --libsubdir='' --datasubdir=''

.ifndef (NOPORTDOCS)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
.endif

do-configure:
	cd ${WRKSRC} && ${CABALCMD} configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${CABALCMD} build && ${CABALCMD} --gen-script register
.ifndef (NOPORTDOCS)
	cd ${WRKSRC} && ${CABALCMD} haddock
.endif

do-install:
	cd ${WRKSRC} && ${CABALCMD} install \
	  && ${INSTALL_SCRIPT} ${WRKSRC}/register.sh ${CABALDIR}/${PORTNAME}-register.sh

.include <bsd.port.mk>
