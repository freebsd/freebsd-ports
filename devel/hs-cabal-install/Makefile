PORTNAME=	cabal-install
PORTVERSION=	3.12.1.0
DISTVERSIONPREFIX=	${PORTNAME}-v
PORTREVISION=	1
CATEGORIES=	devel haskell
EXTRACT_ONLY=	${DISTNAME_DEFAULT}${_GITHUB_EXTRACT_SUFX}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Command-line interface for Cabal and Hackage
WWW=		https://www.haskell.org/cabal/

LICENSE=	BSD3CLAUSE

USES=		cabal:nodefault compiler:c11 pkgconfig python:build

USE_GITHUB=	yes
GH_ACCOUNT=	haskell
GH_PROJECT=	cabal

USE_CABAL=	alex-3.5.1.0 \
		async-2.2.5_1 \
		base16-bytestring-1.0.2.0_1 \
		base64-bytestring-1.2.1.0_1 \
		cryptohash-sha256-0.11.102.1_4 \
		data-array-byte-0.1.0.1_1 \
		directory-1.3.7.1 \
		echo-0.1.4 \
		ed25519-0.0.5.0_8 \
		edit-distance-0.2.2.1_1 \
		hackage-security-0.6.2.6_1 \
		hashable-1.4.6.0 \
		hsc2hs-0.68.10_2 \
		HTTP-4000.4.1_4 \
		lukko-0.1.2 \
		network-3.2.0.0 \
		network-uri-2.6.4.2_1 \
		open-browser-0.2.1.0 \
		os-string-2.0.3 \
		process-1.6.17.0 \
		random-1.2.1.2 \
		regex-base-0.94.0.2_4 \
		regex-posix-0.96.0.1_3 \
		resolv-0.2.0.2_3 \
		safe-exceptions-0.1.7.4_1 \
		semaphore-compat-1.0.0_3 \
		splitmix-0.1.0.5_1 \
		tar-0.6.3.0 \
		th-compat-0.1.5_2 \
		zlib-0.7.1.0

CABAL_EXECUTABLES=	cabal
SKIP_CABAL_EXTRACT=	yes

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
		${PYTHON_CMD} bootstrap/bootstrap.py -d bootstrap/linux-9.6.4.json

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/bin/cabal ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
