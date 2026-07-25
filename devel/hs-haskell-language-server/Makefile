PORTNAME=	haskell-language-server
DISTVERSION=	2.14.0.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	LSP provider implementation for Haskell language
WWW=		https://haskell-language-server.readthedocs.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386

FLAVORS=	default ghc910 ghc98
FLAVOR?=	${FLAVORS:[1]}
.if ${FLAVOR:U} != default
PKGNAMESUFFIX=	-${FLAVOR}
.endif

# Do not use a flavor helper to let Uses/cabal.mk machinery to kick in
.if ${FLAVOR:U} == ghc98
BUILD_DEPENDS=	ghc-${GHC_VERSION}:lang/ghc98
GHC_VERSION=	9.8.4
.endif

.if ${FLAVOR:U} == ghc910
BUILD_DEPENDS=	ghc-${GHC_VERSION}:lang/ghc910
GHC_VERSION=	9.10.3
.endif

USES=		cabal

.for flavor in ${FLAVORS}
.	include "Makefile.cabal.${flavor}"
.endfor

USE_CABAL=		${${FLAVOR}_USE_CABAL}
CABAL_REVISION=		1
CABAL_PROJECT=		append
CABAL_FLAGS=		-dynamic
CABAL_EXECUTABLES=	${PORTNAME} \
			${PORTNAME}-wrapper

.if ${FLAVOR:U} != default
SKIP_CABAL_PLIST=	yes
PLIST_FILES=		bin/${PORTNAME}-${GHC_VERSION}
.endif

# When running 'make makesum' we want USE_CABAL to include packages for all flavors
.ifmake makesum
.for flavor in ${FLAVORS}
USE_CABAL+=		${${flavor}_USE_CABAL}
.endfor
.endif

post-patch:
	${REINPLACE_CMD} 's|jobs: 1|jobs: 2|' ${CABAL_HOME}/.cabal/config

.include <bsd.port.pre.mk>

.if ${FLAVOR:U} != default
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-wrapper
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${GHC_VERSION}
.endif

.include <bsd.port.post.mk>
