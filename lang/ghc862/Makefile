# $FreeBSD$

PORTNAME=	ghc
PORTVERSION=	${GHC_VERSION}
PKGNAMESUFFIX=	862
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PORTVERSION}/:source \
		LOCAL/arrowd/:boot \
		${HACKAGE_SITE}hscolour-${HSCOLOUR_VERSION}/:docs

EXTRACT_ONLY=	${_DISTFILES:C/hscolour.*$//g}
DISTFILES=	ghc-${PORTVERSION}-src${EXTRACT_SUFX}:source \
		hscolour-${HSCOLOUR_VERSION}.tar.gz:docs

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Compiler for the functional language Haskell

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GHC_VERSION=		8.6.2
HSCOLOUR_VERSION=	1.24.4
LLVM_VERSION=		60

CONFLICTS_INSTALL=	ghc-7.4.* ghc-7.6.* ghc-7.8.* ghc-7.10.* ghc-8.0.* ghc-8.4.*

PLIST=			${.CURDIR}/../../lang/ghc/pkg-plist

.include "${.CURDIR}/../../lang/ghc/bsd.ghc.mk"

.include <bsd.port.mk>
