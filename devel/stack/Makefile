# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

# To update this port first go to
# https://github.com/applicative-tech/stack-dependencies, change the
# version in the Makefile there, regenerate the stack-dependencies
# tarball, commit Makefile changes, create a new tag (release)
# matching the new stack version, and upload the tarball.  Finally
# bump the version here.

PORTNAME=	stack
PORTVERSION=	1.5.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	GH \
		https://github.com/applicative-tech/stack-dependencies/releases/download/v${PORTVERSION}/:deps
DISTFILES=	stack-dependencies-${PORTVERSION}${EXTRACT_SUFX}:deps

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform program for developing Haskell programs

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ghc>0:lang/ghc \
		hs-mtl>0:devel/hs-mtl \
		hs-network>0:net/hs-network \
		hs-old-locale>0:devel/hs-old-locale \
		hs-old-time>0:devel/hs-old-time \
		hs-parsec>0:textproc/hs-parsec \
		hs-random>0:devel/hs-random \
		hs-stm>0:devel/hs-stm \
		hs-text>0:devel/hs-text \
		hs-zlib>0:archivers/hs-zlib \
		cabal:devel/hs-cabal-install
LIB_DEPENDS=	libgmp.so:math/gmp \
		libffi.so:devel/libffi
RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		gmake:devel/gmake

USES=		gmake iconv:translit perl5

USE_GITHUB=	yes
GH_ACCOUNT=	applicative-tech
GH_PROJECT=	stack-dependencies

MAKE_ENV=	TARGET="${WRKSRC}" \
		PREFIX="${PREFIX}" \
		STAGEDIR="${STAGEDIR}"

PLIST_FILES=	bin/stack \
		etc/bash_completion.d/_stack.bash \
		share/zsh/site-functions/_stack

.include <bsd.port.mk>
