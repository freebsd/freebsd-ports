# New ports collection makefile for:	zip-archive
# Date created:				December 15, 2008
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zip-archive
PORTVERSION=	0.1.1.3
CATEGORIES=	archivers haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell library for working with zip archives

BUILD_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc \
		hs-zlib>=0.5:${PORTSDIR}/archivers/hs-zlib \
		hs-binary-ghc>=0.4:${PORTSDIR}/devel/hs-binary-ghc \
		hs-utf8-string-ghc>=0.3:${PORTSDIR}/devel/hs-utf8-string-ghc \
		hs-digest-ghc>=0.0.0.1:${PORTSDIR}/security/hs-digest-ghc
RUN_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc \
		hs-zlib>=0.5:${PORTSDIR}/archivers/hs-zlib \
		hs-binary-ghc>=0.4:${PORTSDIR}/devel/hs-binary-ghc \
		hs-utf8-string-ghc>=0.3:${PORTSDIR}/devel/hs-utf8-string-ghc \
		hs-digest-ghc>=0.0.0.1:${PORTSDIR}/security/hs-digest-ghc		

GHC_VERSION=	6.8.3
CABALCMD=	${LOCALBASE}/bin/runghc Setup.lhs
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
