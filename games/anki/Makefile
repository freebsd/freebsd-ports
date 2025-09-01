PORTNAME=	anki
DISTVERSION=	25.07.5
PORTREVISION=	1
# Don't forget to update ${_MY_BUILDHASH} if DISTVERSION changes
CATEGORIES=	games education python
MASTER_SITES=	LOCAL/kai/:yarncache
DISTFILES=	anki-yarn-cache-${DISTVERSION}${EXTRACT_SUFX}:yarncache

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Flashcard trainer with spaced repetition
WWW=		https://apps.ankiweb.net/

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc
NOT_FOR_ARCHS_REASON=	the provided build system written in Rust (= runner) accepts only 64-bit systems.

BUILD_DEPENDS=	protoc:devel/protobuf \
		rsync:net/rsync \
		uv:devel/uv \
		yarn:www/yarn \
		${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy-protobuf>=1.21:devel/py-mypy-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>0:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libzstd.so:archivers/zstd
RUN_DEPENDS=	lame:audio/lame \
		${PYTHON_PKGNAMEPREFIX}pyaudio>0:audio/py-pyaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>0:deskutils/py-send2trash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>0:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Cors>0:www/py-flask-cors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.21:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}waitress>=2.0.0:www/py-waitress@${PY_FLAVOR}

# USES=ssl is required for the compilation of the Rust code
USES=		cargo desktop-file-utils ninja nodejs:build pyqt:6 python \
		shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	ankitects
# Translation files
GH_TUPLE=	ankitects:anki-core-i18n:a019a54:ftlrslib \
		ankitects:anki-desktop-ftl:bc2da83:ftlextra

USE_PYQT=	pyqt6 sip:build webengine

SHEBANG_FILES=	yarn qt/tools/runanki.system.in

CARGO_CARGOTOML=	${WRKSRC}/Cargo.toml

CARGO_BUILD=	no
CARGO_INSTALL=	no

CARGO_TARGET_DIR=	${WRKSRC}/out/rust

# Variables used by the "runner" build system
MAKE_ENV+=	NODE_BINARY=${LOCALBASE}/bin/node \
		OFFLINE_BUILD=1 \
		PROTOC_BINARY=${LOCALBASE}/bin/protoc \
		PYTHON_BINARY=${PYTHON_CMD} \
		UV_BINARY=${LOCALBASE}/bin/uv \
		UV_NO_BUILD_ISOLATION=1 \
		UV_OFFLINE=1 \
		YARN_BINARY=${LOCALBASE}/bin/yarn \
		YARN_CACHE_FOLDER=${_MY_YARNCACHE} \
		out=${WRKSRC}/out
# If RELEASE is unset the "runner" build system omits the
# "--release" flag for cargo(1).
.if !defined(WITH_DEBUG)
MAKE_ENV+=	RELEASE=1
.endif

OPTIONS_DEFAULT=	MPV
OPTIONS_GROUP=		PLAYER
OPTIONS_GROUP_PLAYER=	MPLAYER MPV
OPTIONS_SUB=		yes

MPV_DESC=	mpv media player support

MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPV_RUN_DEPENDS=	mpv:multimedia/mpv

# Should contain the most recent commit that reflects ${DISTVERSION} and must
# be exactly 8 digits otherwise the check for newer versions won't work as
# expected.
_MY_BUILDHASH=	7172b2d2
# Remove ${CARGO_BUILD_TARGET} from ${CARGO_ENV} to avoid problems with
# hardcoded paths as the "runner" build system expects its components
# in ${WRKSRC}/out/rust/debug
_MY_CARGO_ENV=	${CARGO_ENV:C/CARGO_BUILD_TARGET=.+//}
# Path of the cache that is used by www/yarn
_MY_YARNCACHE=	${WRKDIR}/.yarn

post-extract:
# Some parts of the runner build system expects to be in a git repository
	@${TOUCH} ${WRKSRC}/.git
# Prepare the virtual repositories for the translation files
	@${RM} -r ${WRKSRC}/ftl/core-repo ${WRKSRC}/ftl/qt-repo
	@${RLN} ${WRKSRC_ftlrslib} ${WRKSRC}/ftl/core-repo
	@${RLN} ${WRKSRC_ftlextra} ${WRKSRC}/ftl/qt-repo

post-patch:
	@${REINPLACE_CMD} -e 's|\@PREFIX\@|${PREFIX}|' \
		${WRKSRC}/qt/tools/runanki.system.in

pre-configure:
	# Create paths for the Python pseudo venv and link some binaries to it.
	${MKDIR} ${WRKSRC}/out/pyenv/bin
	${LN} -s ${PYTHON_CMD} ${WRKSRC}/out/pyenv/bin/python
	${LN} -s ${LOCALBASE}/bin/protoc-gen-mypy ${WRKSRC}/out/pyenv/bin/protoc-gen-mypy

# Overview of the build process
#
# 1. The "runner" build system is built explicitly with the "--release" flag
#     to avoid issues with hardcoded paths.  Once completed the binaries are
#     placed into ${WRKSRC}/out/rust/release.
# 2. As soon as step 1 is finished, the "runner" build system is executed,
#    which then processes the following steps:
#    * build remaining components of "runner" (= ninja_gen, configure, etc.)
#    * generate the ninja file and run ninja afterwards
#    * create the Python wheel files (via "uv") in ${WRKSRC}/out/wheels
pre-build:
	${ECHO_CMD} -e "${_MY_BUILDHASH}" >> ${WRKSRC}/out/buildhash
	${ECHO_MSG} "===> Building runner build framework"
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${_MY_CARGO_ENV} \
		${CARGO} build --package runner --release --verbose --verbose
do-build:
	${ECHO_MSG} "===> Executing runner build framework"
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${_MY_CARGO_ENV} \
		${WRKSRC}/out/rust/release/runner build wheels

post-build:
	${MKDIR} ${WRKSRC}/out/dist
	cd ${WRKSRC}/out/wheels \
		&& ${UNZIP_NATIVE_CMD} -d ${WRKSRC}/out/dist -x *.orig anki*.whl \
		&& ${UNZIP_NATIVE_CMD} -d ${WRKSRC}/out/dist -x *.orig aqt*.whl
# Update the timestamps otherwise the set dates of the wheels
# (= 1980-01-01 00:00:00) are used
	${FIND} ${WRKSRC}/out/dist -type f -exec ${TOUCH} {} +

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/_aqt \
			${STAGEDIR}${DATADIR}/anki \
			${STAGEDIR}${DATADIR}/aqt \
			${STAGEDIR}${PREFIX}/share/pixmaps \
			${STAGEDIR}${PREFIX}/share/applications
	cd ${WRKSRC}/out/dist/ \
		&& ${COPYTREE_SHARE} _aqt ${STAGEDIR}${DATADIR} "! -name .gitignore" \
		&& ${COPYTREE_SHARE} anki ${STAGEDIR}${DATADIR} "! -name .gitignore" \
		&& ${COPYTREE_SHARE} aqt ${STAGEDIR}${DATADIR} "! -name .gitignore"
	cd ${WRKSRC}/qt/launcher/lin \
		&& ${INSTALL_DATA} anki.xpm anki.png ${STAGEDIR}${PREFIX}/share/pixmaps \
		&& ${INSTALL_DATA} anki.desktop ${STAGEDIR}${PREFIX}/share/applications \
		&& ${INSTALL_MAN} anki.1 ${STAGEDIR}${PREFIX}/share/man/man1
	cd ${WRKSRC}/qt/tools \
		&& ${INSTALL_SCRIPT} runanki.system.in ${STAGEDIR}${PREFIX}/bin/anki

# Autogenerate some parts of the plist file as several *.css and *.mjs files
# have a computed filename.  As it is user-specific it is impossible to know
# their filename in advance.
post-install:
	@${FIND} ${STAGEDIR}${DATADIR}/_aqt/data/web/sveltekit/_app/immutable/ -type f -name "*.css" -o -name "*.mjs" | \
		${SORT} | ${SED} -e 's|${STAGEDIR}||' \
		>> ${TMPPLIST}

# Helper target to make the generation of the yarn cache easier
make-yarn-cache: patch
	@${RM} -r ${_MY_YARNCACHE}
	@cd ${WRKSRC} \
		&& ${LOCALBASE}/bin/yarn --cache-folder ${_MY_YARNCACHE} install --ignore-scripts
	@cd ${WRKDIR} \
		&& ${TAR} -czf ${PORTNAME}-yarn-cache-${DISTVERSION}${EXTRACT_SUFX} .yarn \
		&& ${ECHO_CMD} "Please upload the file ${WRKDIR}/${PORTNAME}-yarn-cache-${DISTVERSION}${EXTRACT_SUFX}"

.include <bsd.port.mk>
