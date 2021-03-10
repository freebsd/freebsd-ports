# $FreeBSD$

PORTNAME=	cabal-install
DISTVERSION=	3.4.0.0
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Command-line interface for Cabal and Hackage

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ghc:lang/ghc

USES=		cabal:nodefault compiler:c11 python:build

USE_GITHUB=	yes
GH_ACCOUNT=	haskell
GH_PROJECT=	cabal
GH_TAGNAME=	${PORTNAME}-${DISTVERSION}

USE_CABAL=	async-2.2.2_1 \
		base16-bytestring-0.1.1.7 \
		base64-bytestring-1.1.0.0 \
		cryptohash-sha256-0.11.101.0_4 \
		digest-0.0.1.2 \
		echo-0.1.3_1 \
		ed25519-0.0.5.0_3 \
		edit-distance-0.2.2.1_1 \
		hackage-security-0.6.0.1_2 \
		hashable-1.3.0.0_1 \
		HTTP-4000.3.14_1 \
		lukko-0.1.1.2 \
		network-3.1.1.1 \
		network-uri-2.6.3.0 \
		random-1.2.0 \
		regex-base-0.94.0.0_1 \
		regex-posix-0.96.0.0_2 \
		resolv-0.1.2.0 \
		splitmix-0.1 \
		tar-0.5.1.1_2 \
		zlib-0.6.2.1_1

CABAL_BOOTSTRAP=	yes

PLIST_FILES=	bin/cabal

post-extract:
	${MKDIR} ${WRKSRC}/_build/tarballs/
.for package in ${USE_CABAL}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${package:C/_[0-9]+//}/${package:C/_[0-9]+//}${EXTRACT_SUFX} ${WRKSRC}/_build/tarballs/

.	if ${package:C/[^_]*//:S/_//} != ""
		${CP} ${DISTDIR}/${DIST_SUBDIR}/${package:C/_[0-9]+//}/revision/${package:C/[^_]*//:S/_//}.cabal ${WRKSRC}/_build/tarballs/${package:C/[0-9._]*$//:S/-$//}.cabal
.	else
		tar -C ${WRKDIR} -xf ${DISTDIR}/${DIST_SUBDIR}/${package:C/_[0-9]+//}/${package:C/_[0-9]+//}${EXTRACT_SUFX} --include='*.cabal'
		${MV} ${WRKDIR}/${package:C/_[0-9]+//}/${package:C/[0-9._]*$//:S/-$//}.cabal ${WRKSRC}/_build/tarballs/${package:C/[0-9._]*$//:S/-$//}.cabal
.	endif
.endfor

do-build:
	cd ${WRKSRC} && \
		${PYTHON_CMD} bootstrap/bootstrap.py -d bootstrap/linux-8.10.1.json

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/bin/cabal ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
