PORTNAME=	nimble
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.0
CATEGORIES=	devel

MAINTAINER=	ports@nicandneal.net
COMMENT=	Package manager for the Nim programming language
WWW=		https://github.com/nim-lang/nimble

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${LOCALBASE}/nim/bin/nim:lang/nim
RUN_DEPENDS=	${LOCALBASE}/nim/bin/nim:lang/nim

NIMVER=		2.2.4

USE_GITHUB=	yes
GH_ACCOUNT=	nim-lang guzba:zippy
GH_PROJECT=	sat:sat checksums:checksums nim:nim zippy:zippy
GH_TAGNAME=	faf1617f44d7632ee9601ebc13887644925dcc01:sat \
		f8f6bd34bfa3fe12c64b919059ad856a96efcba0:checksums \
		a99f6a7d8a8e3e0213b3cad0daf0ea974bf58e3f:zippy \
		v${NIMVER}:nim

post-extract:
	# Nim gets extracted with a different name to WRKSRC_nim!
	@${MV} ${WRKDIR}/Nim-${NIMVER} ${WRKSRC_nim}

post-patch:
	@${REINPLACE_CMD} -e 's|import sat/sat|import "${WRKSRC_sat}"/src/sat/sat|g' ${WRKSRC}/src/nimble.nim
	@${REINPLACE_CMD} -e 's|import pkg/checksums/sha1|import "${WRKSRC_checksums}"/src/checksums/sha1|g' ${WRKSRC}/src/nimblepkg/sha1hashes.nim
	@${REINPLACE_CMD} -e 's|from "$$nim" / compiler/nimblecmd|from "${WRKSRC_nim}"/compiler/nimblecmd|g' ${WRKSRC}/src/nimblepkg/tools.nim
	@${REINPLACE_CMD} -e 's|import ../dist/checksums/src/checksums/sha1|import "${WRKSRC_checksums}"/src/checksums/sha1|g' ${WRKSRC_nim}/compiler/nimblecmd.nim
	@${REINPLACE_CMD} -e 's|import pkg/checksums/sha1|import "${WRKSRC_checksums}"/src/checksums/sha1|g' ${WRKSRC}/src/nimblepkg/checksums.nim
	@${REINPLACE_CMD} -e 's|import sat/|import "${WRKSRC_sat}"/src/sat/|g' ${WRKSRC}/src/nimblepkg/nimblesat.nim
	@${REINPLACE_CMD} -e 's|import zippy/|import "${WRKSRC_zippy}"/src/zippy/|g' ${WRKSRC}/src/nimblepkg/downloadnim.nim
	@${REINPLACE_CMD} -e 's|, zippy|, ../zippy|g' ${WRKSRC_zippy}/src/zippy/tarballs_v1.nim
	@${REINPLACE_CMD} -e 's|, zippy|, ../zippy|g' ${WRKSRC_zippy}/src/zippy/ziparchives_v1.nim
	@${REINPLACE_CMD} -e 's|, zippy|, ../zippy|g' ${WRKSRC_zippy}/src/zippy/ziparchives.nim

do-build:
	@cd ${WRKSRC} && ${LOCALBASE}/nim/bin/nim c -d:release --noNimblePath -d:nimNimbleBootstrap --parallelBuild=${MAKE_JOBS_NUMBER} --path:${LOCALBASE}/nim --nimcache:${WRKSRC}/nimcache src/nimble

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nimble ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/nimble.bash-completion ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/nimble.zsh-completion ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
