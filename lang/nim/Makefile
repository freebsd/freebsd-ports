PORTNAME=	nim
DISTVERSION=	2.2.4
CATEGORIES=	lang
MASTER_SITES=	https://nim-lang.org/download/

MAINTAINER=	ports@nicandneal.net
COMMENT=	Nim programming language
WWW=		https://nim-lang.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/copying.txt

DEPRECATED=	Depends on expired www/npm-node18
EXPIRATION_DATE=2025-09-01

LIB_DEPENDS=	libpcre.so:devel/pcre
TEST_DEPENDS=	node18>=0:www/node

USES=		compiler:c11 cpe tar:xz
CPE_VENDOR=	nim-lang

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DOCS TOOLS
OPTIONS_DEFAULT=	TOOLS
OPTIONS_EXCLUDE_powerpc64=	DOCS
OPTIONS_SUB=		yes

TOOLS_DESC=	Build and install nim tools, not including nimble nor nimfind

TEST_BINARY_ALIAS=	node=nodejs

.include <bsd.port.pre.mk>

TLIST=		nimgrep nimpretty nimsuggest testament

NIMDIR=	${STAGEDIR}${PREFIX}/nim

do-build:
	cd ${WRKSRC} && ${SETENV} CC="${CC}" LINKER="${CC}" \
		COMP_FLAGS="${CPPFLAGS} ${CFLAGS}" LINK_FLAGS="${LDFLAGS}" \
		${SH} build.sh
	cd ${WRKSRC} && bin/nim c --parallelBuild=${MAKE_JOBS_NUMBER} \
		--nimcache=${WRKDIR}/nimcache -d:release koch
	cd ${WRKSRC} && ./koch boot --parallelBuild=${MAKE_JOBS_NUMBER} \
		-d:release --nimcache=${WRKDIR}/nimcache
	cd ${WRKSRC} && bin/nim c --parallelBuild=${MAKE_JOBS_NUMBER} \
		-d:release --nimcache=${WRKDIR}/nimcache --app:lib \
		-d:createNimRtl lib/nimrtl.nim

do-build-DOCS-on:
	cd ${WRKSRC} && ./koch --localdocs docs \
		-d:release --nimcache=${WRKDIR}/nimcache --docCmd=skip

do-build-TOOLS-on:
	cd ${WRKSRC} && ./koch tools --parallelBuild=${MAKE_JOBS_NUMBER} \
		-d:release --nimcache=${WRKSRC}/nimcache

do-install:
	${MKDIR} ${NIMDIR}
	${MKDIR} ${NIMDIR}/bin
	# Install nim compiler
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nim ${NIMDIR}/bin
	${STRIP_CMD} ${NIMDIR}/bin/nim
	# Install lib nim rtl
	${MKDIR} ${NIMDIR}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/libnimrtl.so ${NIMDIR}/lib
	# Install nim lib files
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${NIMDIR}/lib "! -name libnimrtl.so")
	${MKDIR} ${NIMDIR}/lib/compiler
	(cd ${WRKSRC}/compiler && ${COPYTREE_SHARE} . ${NIMDIR}/lib/compiler "! -name nim ! -name nim1")
	(cd ${WRKSRC}/dist/checksums && ${COPYTREE_SHARE} . ${NIMDIR}/lib/dist/checksums)
	# Configuration files
	${MKDIR} ${NIMDIR}/config
.for file in nim.cfg nimdoc.cfg nimdoc.tex.cfg
	${INSTALL_DATA} ${WRKSRC}/config/${file} ${NIMDIR}/config
.endfor

do-install-DOCS-on:
	${FIND} ${WRKSRC}/doc -name "*.idx" -delete
	${MKDIR} ${NIMDIR}/doc
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${NIMDIR}/doc)
	${MKDIR} ${NIMDIR}/tools/dochack
	${INSTALL_SCRIPT} ${WRKSRC}/tools/dochack/dochack.nim ${NIMDIR}/tools/dochack
	${INSTALL_SCRIPT} ${WRKSRC}/tools/dochack/dochack.js ${NIMDIR}/tools/dochack
	${INSTALL_SCRIPT} ${WRKSRC}/tools/dochack/fuzzysearch.nim ${NIMDIR}/tools/dochack

do-install-TOOLS-on:
.for t in ${TLIST}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${t} ${NIMDIR}/bin
.endfor

do-test:
	cd ${WRKSRC} && ${SETENV} ./koch test all -d:release \
	--nimcache=${WRKDIR}/nimcache --putenv:"PATH=${PATH}"

.include <bsd.port.post.mk>
