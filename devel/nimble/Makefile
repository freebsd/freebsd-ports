PORTNAME=	nimble
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.2
CATEGORIES=	devel

MAINTAINER=	ports@nicandneal.net
COMMENT=	Package manager for the Nim programming language
WWW=		https://github.com/nim-lang/nimble

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

DEPRECATED=	Depends on expiring lang/nim
EXPIRATION_DATE=2025-09-01

BUILD_DEPENDS=	${LOCALBASE}/nim/bin/nim:lang/nim
RUN_DEPENDS=	${LOCALBASE}/nim/bin/nim:lang/nim

NIMVER=		2.2.0

USE_GITHUB=	yes
GH_ACCOUNT=	nim-lang
GH_PROJECT=	sat:sat checksums:checksums nim:nim
GH_TAGNAME=	faf1617f44d7632ee9601ebc13887644925dcc01:sat \
		bd9bf4eaea124bf8d01e08f92ac1b14c6879d8d3:checksums \
		v${NIMVER}:nim

PLIST_FILES=	bin/nimble

post-extract:
	# Nim gets extracted with a different name to WRKSRC_nim!
	@${MV} ${WRKDIR}/Nim-${NIMVER} ${WRKSRC_nim}

post-patch:
	@${REINPLACE_CMD} -e 's|import ../dist/sat/src/sat/sat|import "${WRKSRC_sat}"/src/sat/sat|g' ${WRKSRC}/src/nimble.nim
	@${REINPLACE_CMD} -e 's|import ../../dist/checksums/src/checksums/sha1| import "${WRKSRC_checksums}"/src/checksums/sha1|g' ${WRKSRC}/src/nimblepkg/sha1hashes.nim
	@${REINPLACE_CMD} -e 's|from "$$nim" / compiler/nimblecmd|from "${WRKSRC_nim}"/compiler/nimblecmd|g' ${WRKSRC}/src/nimblepkg/tools.nim
	@${REINPLACE_CMD} -e 's|import ../dist/checksums/src/checksums/sha1|import "${WRKSRC_checksums}"/src/checksums/sha1|g' ${WRKSRC_nim}/compiler/nimblecmd.nim
	@${REINPLACE_CMD} -e 's|import ../../dist/checksums/src/checksums/sha1|import "${WRKSRC_checksums}"/src/checksums/sha1|g' ${WRKSRC}/src/nimblepkg/checksums.nim
	@${REINPLACE_CMD} -e 's|import ../../dist/sat/src/sat/|import "${WRKSRC_sat}"/src/sat/|g' ${WRKSRC}/src/nimblepkg/nimblesat.nim

do-build:
	@cd ${WRKSRC} && ${LOCALBASE}/nim/bin/nim c -d:release --noNimblePath -d:nimNimbleBootstrap --parallelBuild=${MAKE_JOBS_NUMBER} --path:${LOCALBASE}/nim --nimcache:${WRKSRC}/nimcache src/nimble

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nimble ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
