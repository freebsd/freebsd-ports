PORTNAME=	cabal-install
PORTVERSION=	3.18.2.0
DISTVERSIONPREFIX=	${PORTNAME}-v
CATEGORIES=	devel haskell
EXTRACT_ONLY=	${DISTNAME_DEFAULT}${_GITHUB_EXTRACT_SUFX}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Command-line interface for Cabal and Hackage
WWW=		https://www.haskell.org/cabal/

LICENSE=	BSD3CLAUSE

TEST_DEPENDS=	git:devel/git

USES=		cabal:nodefault compiler:c11 pkgconfig python:build

USE_GITHUB=	yes
GH_ACCOUNT=	haskell
GH_PROJECT=	cabal

USE_CABAL=	alex-3.5.4.2 \
		async-2.2.6 \
		atomic-counter-0.1.2.4 \
		base16-bytestring-1.0.2.0_1 \
		base64-bytestring-1.2.1.0_1 \
		cryptohash-sha256-0.11.102.1_6 \
		directory-1.3.9.0_1 \
		directory-ospath-streaming-0.3_1 \
		echo-0.1.4 \
		ed25519-0.0.5.0_9 \
		edit-distance-0.2.2.1_1 \
		file-io-0.1.5 \
		filepath-1.5.4.0 \
		hackage-security-0.6.3.3 \
		hashable-1.5.1.0 \
		hsc2hs-0.68.10_5 \
		HTTP-4000.5.0_1 \
		network-3.2.8.0 \
		network-uri-2.6.4.2_1 \
		open-browser-0.5.1.0 \
		os-string-2.0.7 \
		process-1.6.30.0 \
		random-1.3.1 \
		regex-base-0.94.0.3 \
		regex-posix-0.96.0.2 \
		resolv-0.2.0.3 \
		safe-exceptions-0.1.7.4_1 \
		semaphore-compat-2.0.1 \
		splitmix-0.1.3.2 \
		tar-0.7.1.0_1 \
		th-compat-0.1.7 \
		unix-2.8.6.0_1 \
		unordered-containers-0.2.21_2 \
		zlib-0.7.1.1

CABAL_EXECUTABLES=	cabal
SKIP_CABAL_EXTRACT=	yes

TESTING_UNSAFE=	Tests require network access
.if make(test)
CABAL_HOME=	${WRKDIR}/cabal-test-home
.endif

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
		${PYTHON_CMD} bootstrap/bootstrap.py -d bootstrap/linux-9.12.4.json

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/bin/cabal ${STAGEDIR}${PREFIX}/bin/

do-test:
	cd ${WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${CABAL_HOME_ENV} ${CABAL_CMD} update
	cd ${WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${CABAL_HOME_ENV} ${CABAL_CMD} test all

.include <bsd.port.mk>
