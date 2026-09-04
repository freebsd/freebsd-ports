PORTNAME=	nimble
DISTVERSIONPREFIX=	v
DISTVERSION=	0.24.1
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
GH_ACCOUNT=	nim-lang guzba:zippy status-im:bearssl status-im:bearsslc status-im:chronos status-im:httputils arnetheduck:results status-im:stew
GH_PROJECT=	sat:sat checksums:checksums nim-bearssl:bearssl BearSSL:bearsslc nim-chronos:chronos nim-http-utils:httputils nim:nim nim-results:results nim-stew:stew zippy:zippy
GH_TAGNAME=	e63eaea8baf00bed8bcd5a29ffd8823abb265b39:sat \
		25197fec8a3988d1153be7a1a79890b70e69d6db:bearssl \
		7bea48e5e850ab4cafbe68d3765cdaba13a86d6f:bearsslc \
		f8f6bd34bfa3fe12c64b919059ad856a96efcba0:checksums \
		bd92f8e089ccd391b9762b7035215bea2307dbc9:chronos \
		f142cb2e8bd812dd002a6493b6082827bb248592:httputils \
		b319652e98a198fa881ca70a76754c2dd6f09804:results \
		83eb1157963b7f49351dbdd858355fa990bbe23c:stew \
		bcb8c1e1be6abb0a0e35a3c6040cdd9391cc993f:zippy \
		v${NIMVER}:nim

post-extract:
	# Nim gets extracted with a different name to WRKSRC_nim!
	@${MV} ${WRKDIR}/Nim-${NIMVER} ${WRKSRC_nim}
	@${LN} -sF ${WRKSRC_bearsslc} ${WRKSRC_bearssl}/bearssl/csources

post-patch:
	# Nimble
	@${REINPLACE_CMD} -e 's|import chronos|import "${WRKSRC_chronos}"/chronos|g' ${WRKSRC}/src/nimble.nim

	@${REINPLACE_CMD} -e 's|import sat/|import "${WRKSRC_sat}"/src/sat/|g' ${WRKSRC}/src/nimble.nim

	@${REINPLACE_CMD} -e 's|import pkg/checksums/|import "${WRKSRC_checksums}"/src/checksums/|g' ${WRKSRC}/src/nimblepkg/checksums.nim

	@${REINPLACE_CMD} -e 's|import chronos|import "${WRKSRC_chronos}"/chronos|g' ${WRKSRC}/src/nimblepkg/download.nim

	@${REINPLACE_CMD} -e 's|import zippy/|import "${WRKSRC_zippy}"/src/zippy/|g' ${WRKSRC}/src/nimblepkg/downloadnim.nim
	@${REINPLACE_CMD} -e 's|import chronos|import "${WRKSRC_chronos}"/chronos|g' ${WRKSRC}/src/nimblepkg/downloadnim.nim

	@${REINPLACE_CMD} -e 's|import chronos|import "${WRKSRC_chronos}"/chronos|g' ${WRKSRC}/src/nimblepkg/install.nim

	@${REINPLACE_CMD} -e 's|import chronos|import "${WRKSRC_chronos}"/chronos|g' ${WRKSRC}/src/nimblepkg/nimenv.nim

	@${REINPLACE_CMD} -e 's|import chronos|import "${WRKSRC_chronos}"/chronos|g' ${WRKSRC}/src/nimblepkg/nimresolution.nim

	@${REINPLACE_CMD} -e 's|import chronos|import "${WRKSRC_chronos}"/chronos|g' ${WRKSRC}/src/nimblepkg/nimblesat.nim
	@${REINPLACE_CMD} -e 's|import sat/|import "${WRKSRC_sat}"/src/sat/|g' ${WRKSRC}/src/nimblepkg/nimblesat.nim

	@${REINPLACE_CMD} -e 's|import chronos|import "${WRKSRC_chronos}"/chronos|g' ${WRKSRC}/src/nimblepkg/options.nim

	@${REINPLACE_CMD} -e 's|import chronos/apps/http/httpclient|import "${WRKSRC_chronos}"/chronos/apps/http/httpclient|g' ${WRKSRC}/src/nimblepkg/packageinfo.nim

	@${REINPLACE_CMD} -e 's|import zippy|import "${WRKSRC_zippy}"/src/zippy|g' ${WRKSRC}/src/nimblepkg/packageinfo.nim

	@${REINPLACE_CMD} -e 's|import chronos|import "${WRKSRC_chronos}"/chronos|g' ${WRKSRC}/src/nimblepkg/publish.nim

	@${REINPLACE_CMD} -e 's|import pkg/checksums/|import "${WRKSRC_checksums}"/src/checksums/|g' ${WRKSRC}/src/nimblepkg/sha1hashes.nim

	@${REINPLACE_CMD} -e 's|from "$$nim" / compiler/nimblecmd|from "${WRKSRC_nim}"/compiler/nimblecmd|g' ${WRKSRC}/src/nimblepkg/tools.nim

	@${REINPLACE_CMD} -e 's|, chronos, chronos/|, "${WRKSRC_chronos}"/chronos, "${WRKSRC_chronos}"/chronos/|g' ${WRKSRC}/src/nimblepkg/tools.nim

	@${REINPLACE_CMD} -e 's|import chronos|import "${WRKSRC_chronos}"/chronos|g' ${WRKSRC}/src/nimblepkg/versiondiscovery.nim

	# BearSSL
	@${REINPLACE_CMD} -e 's|{.compile: bearPath & "/../certs/cacert.c".}|{.compile: "${WRKSRC_bearssl}/bearssl/certs/cacert.c".}|g' ${WRKSRC_bearssl}/bearssl/certs/cacert.nim

	# Chronos
	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/apps/http/httpclient.nim
	@${REINPLACE_CMD} -e 's|\], httputils, results|\], "${WRKSRC_httputils}"/httputils, "${WRKSRC_results}"/results|g' ${WRKSRC_chronos}/chronos/apps/http/httpclient.nim

	@${REINPLACE_CMD} -e 's|import results, httputils, stew/base64|import "${WRKSRC_results}"/results, "${WRKSRC_httputils}"/httputils,"${WRKSRC_stew}"/stew/base64|g' ${WRKSRC_chronos}/chronos/apps/http/httpcommon.nim

	@${REINPLACE_CMD} -e 's|import results, httputils|import "${WRKSRC_results}"/results, "${WRKSRC_httputils}"/httputils|g' ${WRKSRC_chronos}/chronos/apps/http/multipart.nim

	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/apps/http/httptable.nim

	@${REINPLACE_CMD} -e 's|import stew/\[byteutils\], results|import "${WRKSRC_stew}"/stew/\[byteutils\], "${WRKSRC_results}"/results|g' ${WRKSRC_chronos}/chronos/asyncproc.nim

	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/bipbuffer.nim

	@${REINPLACE_CMD} -e 's|import results|import "${WRKSRC_results}"/results|g' ${WRKSRC_chronos}/chronos/handles.nim

	@${REINPLACE_CMD} -e 's|import results|import "${WRKSRC_results}"/results|g' ${WRKSRC_chronos}/chronos/internal/asyncengine.nim

	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/internal/asyncfutures.nim

	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/ioselects/ioselectors_kqueue.nim

	@${REINPLACE_CMD} -e 's|import results|import "${WRKSRC_results}"/results|g' ${WRKSRC_chronos}/chronos/osutils.nim

	@${REINPLACE_CMD} -e 's|import results|import "${WRKSRC_results}"/results|g' ${WRKSRC_chronos}/chronos/selectors2.nim

	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/srcloc.nim

	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/streams/asyncstream.nim

	@${REINPLACE_CMD} -e 's|import results|import "${WRKSRC_results}"/results|g' ${WRKSRC_chronos}/chronos/streams/boundstream.nim
	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/streams/boundstream.nim

	@${REINPLACE_CMD} -e 's|import results|import "${WRKSRC_results}"/results|g' ${WRKSRC_chronos}/chronos/streams/chunkstream.nim

	@${REINPLACE_CMD} -e 's| bearssl/| "${WRKSRC_bearssl}"/bearssl/|g' ${WRKSRC_chronos}/chronos/streams/tlsstream.nim
	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/streams/tlsstream.nim

	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/timer.nim

	@${REINPLACE_CMD} -e 's|import results|import "${WRKSRC_results}"/results|g' ${WRKSRC_chronos}/chronos/transports/common.nim
	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/transports/common.nim

	@${REINPLACE_CMD} -e 's|import results|import "${WRKSRC_results}"/results|g' ${WRKSRC_chronos}/chronos/transports/datagram.nim
	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/transports/datagram.nim

	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/transports/ipnet.nim

	@${REINPLACE_CMD} -e 's|import results|import "${WRKSRC_results}"/results|g' ${WRKSRC_chronos}/chronos/transports/stream.nim
	@${REINPLACE_CMD} -e 's|import stew/|import "${WRKSRC_stew}"/stew/|g' ${WRKSRC_chronos}/chronos/transports/stream.nim

	# HTTPUtils
	@${REINPLACE_CMD} -e 's|import results|import "${WRKSRC_results}"/results|g' ${WRKSRC_httputils}/httputils.nim

	# Nim
	@${REINPLACE_CMD} -e 's|import ../dist/checksums/src/checksums/sha1|import "${WRKSRC_checksums}"/src/checksums/sha1|g' ${WRKSRC_nim}/compiler/nimblecmd.nim

	# Stew
	@${REINPLACE_CMD} -e 's|import pkg/results|import "${WRKSRC_results}"/results|g' ${WRKSRC_stew}/stew/base10.nim

	# Zippy
	@${REINPLACE_CMD} -e 's|, zippy|, ../zippy|g' ${WRKSRC_zippy}/src/zippy/tarballs_v1.nim

	@${REINPLACE_CMD} -e 's|, zippy|, ../zippy|g' ${WRKSRC_zippy}/src/zippy/ziparchives.nim

	@${REINPLACE_CMD} -e 's|, zippy|, ../zippy|g' ${WRKSRC_zippy}/src/zippy/ziparchives_v1.nim

do-build:
	@cd ${WRKSRC} && ${LOCALBASE}/nim/bin/nim c -d:release --noNimblePath -d:nimNimbleBootstrap --parallelBuild=${MAKE_JOBS_NUMBER} --path:${LOCALBASE}/nim --nimcache:${WRKSRC}/nimcache src/nimble

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nimble ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/nimble.bash-completion ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/nimble.zsh-completion ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
