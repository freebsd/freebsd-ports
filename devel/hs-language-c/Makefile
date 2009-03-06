# New ports collection makefile for:	hs-language-c-ghc
# Date created:				March 2, 2009
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	language-c
PORTVERSION=	0.3.1.1
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Analysis and generation of C code in Haskell

BUILD_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc \
		alex:${PORTSDIR}/devel/hs-alex \
		happy:${PORTSDIR}/devel/hs-happy
RUN_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc

GHC_VERSION=	6.8.3
CABALCMD=	${LOCALBASE}/bin/runghc Setup.hs
CABALDIR=	lib/ghc-${GHC_VERSION}/cabal

SUBDIR=		lib/${PORTNAME}-${PORTVERSION}
PLIST_SUB=	GHC_VERSION=${GHC_VERSION}		\
		PORTNAME=${PORTNAME}			\
		PORTVERSION=${PORTVERSION}		\
		SUBDIR=${CABALDIR}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	LICENSE html

CONFIGURE_ARGS=	--ghc --prefix=${PREFIX} --libdir=${PREFIX}/${CABALDIR} --libsubdir='' --datasubdir=''

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
PLIST_SUB+=	RMLIC="@comment "
.else
PLIST_SUB+=	RMLIC=""
.endif

do-configure:
	cd ${WRKSRC} && ${CABALCMD} configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${CABALCMD} build && ${CABALCMD} --gen-script register
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${CABALCMD} haddock
.endif

do-install:
	cd ${WRKSRC} && ${CABALCMD} install
	${INSTALL_SCRIPT} ${WRKSRC}/register.sh ${PREFIX}/${CABALDIR}/${PORTNAME}-register.sh

.include <bsd.port.mk>
