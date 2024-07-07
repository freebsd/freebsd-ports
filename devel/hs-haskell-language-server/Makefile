PORTNAME=	haskell-language-server
DISTVERSION=	2.9.0.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	LSP provider implementation for Haskell language
WWW=		https://github.com/haskell/haskell-language-server/

LICENSE=	APACHE20

BROKEN_aarch64=	compiler crashes

FLAVORS=	default ghc92
FLAVOR?=	${FLAVORS:[1]}
.if ${FLAVOR:U} != default
PKGNAMESUFFIX=	-${FLAVOR}
.endif

# Do not use a flavor helper to let Uses/cabal.mk machinery to kick in
.if ${FLAVOR:U} == ghc92
BUILD_DEPENDS=	ghc-9.2.8:lang/ghc92
GHC_VERSION=	9.2.8
.endif

USES=		cabal

USE_GITHUB=	yes
GH_ACCOUNT=	haskell

.for flavor in ${FLAVORS}
.	include "Makefile.cabal.${flavor}"
.endfor

USE_CABAL=		${${FLAVOR}_USE_CABAL}
CABAL_PROJECT=		append
CABAL_FLAGS=		-dynamic
CABAL_EXECUTABLES=	${PORTNAME} \
			${PORTNAME}-wrapper

NOT_FOR_ARCHS=		i386

.if ${FLAVOR:U} != default
SKIP_CABAL_PLIST=	yes
PLIST_FILES=		bin/${PORTNAME}-${GHC_VERSION}
.endif

# When running 'make makesum' we want USE_CABAL to include packages for all flavors
.ifmake makesum
.for f in ${FLAVORS}
USE_CABAL+=		${${f}_USE_CABAL}
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
# compiler goes out of memory
BUILD_ARGS+=	--disable-optimization
.endif

.if ${FLAVOR:U} != default
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-wrapper
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${GHC_VERSION}
.endif

.include <bsd.port.post.mk>
