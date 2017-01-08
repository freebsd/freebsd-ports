# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

# To update this port first go to
# https://github.com/applicative-tech/stack-dependencies, change the
# version in the Makefile there, regenerate the stack-dependencies
# tarball, commit Makefile changes, create a new tag (release)
# matching the new stack version, and upload the tarball.  Finally
# bump the version here.

PORTNAME=	stack
PORTVERSION=	1.3.2
CATEGORIES=	devel haskell
MASTER_SITES=	GH \
		https://github.com/applicative-tech/stack-dependencies/releases/download/${PORTVERSION}/:deps
DISTFILES=	stack-dependencies-${PORTVERSION}${EXTRACT_SUFX}:deps

MAINTAINER=	t@tobik.me
COMMENT=	Cross-platform program for developing Haskell programs

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ghc>0:lang/ghc \
		cabal:devel/hs-cabal-install
LIB_DEPENDS=	libiconv.so:converters/libiconv \
		libgmp.so:math/gmp \
		libffi.so:devel/libffi
RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		gcc:lang/gcc \
		gmake:devel/gmake
USES=		gmake perl5

USE_GITHUB=	yes
GH_ACCOUNT=	applicative-tech
GH_PROJECT=	stack-dependencies

MAKE_ENV+=	TARGET="${WRKSRC}" \
		PREFIX="${PREFIX}" \
		STAGEDIR="${STAGEDIR}"

PLIST_FILES=	bin/stack \
		etc/bash_completion.d/_stack.bash \
		share/zsh/site-functions/_stack

.include <bsd.port.mk>
