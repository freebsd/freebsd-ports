PORTNAME=	cabal-install
PORTVERSION=	3.10.1.0
DISTVERSIONPREFIX=	${PORTNAME}-v
PORTREVISION=	4
CATEGORIES=	devel haskell
EXTRACT_ONLY=	${DISTNAME_DEFAULT}${_GITHUB_EXTRACT_SUFX}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Command-line interface for Cabal and Hackage
WWW=		https://www.haskell.org/cabal/

LICENSE=	BSD3CLAUSE

USES=		cabal:nodefault compiler:c11 python:build

USE_GITHUB=	yes
GH_ACCOUNT=	haskell
GH_PROJECT=	cabal

USE_CABAL=	async-2.2.4_2 \
		base16-bytestring-1.0.2.0 \
		base64-bytestring-1.2.1.0 \
		cryptohash-sha256-0.11.102.1_1 \
		data-array-byte-0.1.0.1_1 \
		directory-1.3.7.1 \
		echo-0.1.4 \
		ed25519-0.0.5.0_6 \
		edit-distance-0.2.2.1_1 \
		hackage-security-0.6.2.3_2 \
		hashable-1.4.2.0 \
		HTTP-4000.4.1_1 \
		lukko-0.1.1.3_3 \
		network-3.1.2.7 \
		network-uri-2.6.4.2 \
		process-1.6.17.0 \
		random-1.2.1.1 \
		regex-base-0.94.0.2_1 \
		regex-posix-0.96.0.1_1 \
		resolv-0.1.2.0_5 \
		safe-exceptions-0.1.7.3 \
		splitmix-0.1.0.4_2 \
		tar-0.5.1.1_5 \
		th-compat-0.1.4 \
		zlib-0.6.3.0_1

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
		${PYTHON_CMD} bootstrap/bootstrap.py -d bootstrap/linux-9.4.4.json

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/bin/cabal ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
