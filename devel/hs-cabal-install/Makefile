PORTNAME=	cabal-install
PORTVERSION=	3.6.2.0
CATEGORIES=	devel haskell
EXTRACT_ONLY=	${DISTNAME_DEFAULT}${_GITHUB_EXTRACT_SUFX}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Command-line interface for Cabal and Hackage

LICENSE=	BSD3CLAUSE

USES=		cabal:nodefault compiler:c11 python:build

USE_GITHUB=	yes
GH_ACCOUNT=	haskell
GH_PROJECT=	cabal
GH_TAGNAME=	${PORTNAME}-v${PORTVERSION}

USE_CABAL=	async-2.2.4 \
		base16-bytestring-1.0.2.0 \
		base64-bytestring-1.2.1.0 \
		cryptohash-sha256-0.11.102.1 \
		echo-0.1.4 \
		ed25519-0.0.5.0_5 \
		edit-distance-0.2.2.1_1 \
		hackage-security-0.6.1.0 \
		hashable-1.3.3.0 \
		HTTP-4000.3.16_1 \
		lukko-0.1.1.3_2 \
		network-3.1.2.2 \
		network-uri-2.6.4.1 \
		random-1.2.1 \
		regex-base-0.94.0.1_1 \
		regex-posix-0.96.0.1 \
		resolv-0.1.2.0_4 \
		splitmix-0.1.0.4 \
		tar-0.5.1.1_5 \
		th-compat-0.1.3 \
		zlib-0.6.2.3_1

SKIP_CABAL_EXTRACT=	yes
SKIP_CABAL_PLIST=	yes

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
		${PYTHON_CMD} bootstrap/bootstrap.py -d bootstrap/linux-8.10.7.json

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/bin/cabal ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
