# $FreeBSD$

PORTNAME=	renpy
PORTVERSION=	7.4.4
DISTVERSIONSUFFIX=-sdk
CATEGORIES=	games devel
MASTER_SITES=	https://www.renpy.org/dl/${PORTVERSION}/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Framework for developing visual-novel type games

LICENSE=	APACHE20 BSD3CLAUSE DejaVu LGPL21+ MIT OFL11 ZLIB
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_NAME_DejaVu=	Bitstream Vera and Arev fonts license
LICENSE_FILE_DejaVu=	${WRKSRC}/renpy/common/DejaVuSans.txt
LICENSE_PERMS_DejaVu=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

# Extend expiration if lang/python27 is also extended
# https://github.com/renpy/renpy/issues/2003
DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-12-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}game_sdl2>0:devel/py-game_sdl2@${PY_FLAVOR}
LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libpng.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}game_sdl2>0:devel/py-game_sdl2@${PY_FLAVOR}

# Upstream tends to reroll distfiles before moving under /release/
PORTSCOUT=	site:http://www.renpy.org/dl/release/

USES=		python:2.7 sdl shebangfix tar:bz2
USE_PYTHON=	autoplist distutils cython
USE_SDL=	sdl2
EXCLUDE=	fribidi-src gen 'module/*.py[co]' 'renpy/*.py[co]'
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}
SHEBANG_FILES=	renpy.py launcher/game/tkaskdir.py
TARGET_ORDER_OVERRIDE=610:fix-shebang
BUILD_WRKSRC=	${WRKSRC}/module
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKE_ENV+=	RENPY_DEPS_INSTALL="${LOCALBASE}" \
		RENPY_CYTHON=cython-${PYTHON_VER}
PORTDATA=	gui launcher renpy renpy.py
PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME}

DESKTOP_ENTRIES="Ren'Py" \
		"" \
		"${DATADIR}/launcher/game/images/logo32.png" \
		"${PORTNAME} %f" \
		"Development;Game;AdventureGame;" \
		""

OPTIONS_DEFAULT=TKINTER DIST
OPTIONS_DEFINE=	DOCS DIST EXAMPLES TKINTER

DIST_DESC=	Distribution runtimes for Windows, OS X, Linux
DIST_VARS=	LICENSE+="ART20 PSFL" \
		PORTDATA+="lib renpy.app renpy.exe renpy-32.exe renpy.sh"
EXAMPLES_VARS=	PORTDATA+="the_question tutorial"
TKINTER_DESC=	Install Tkinter to allow choosing Projects Directory
TKINTER_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}

post-extract:
	@${FIND} ${WRKSRC}/lib ${WRKSRC}/renpy.app -type d -empty -delete

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/python[[:>:]],${PYTHON_CMD},' \
		${WRKSRC}/launcher/game/choose_directory.rpy
# Avoid having to add -I/usr/include -L/usr/lib
	@${REINPLACE_CMD} '/library("z")/d' ${BUILD_WRKSRC}/${PYSETUP}

post-build:
	@${PYTHON_CMD} -m compileall -d ${DATADIR} ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall -d ${DATADIR} ${WRKSRC}

add-plist-post: add-empty-dirs
add-empty-dirs:
# Keep images directory in gui and templates, see renpy@d81ea29
	${FIND} ${WRKSRC} -type d -empty \
		! \( -name "gen" -or -name "saves" -or -name "pysdlsound" \) | \
		${SED} 's,^${WRKSRC},@dir ${DATADIR},' >>${TMPPLIST}

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name \*.so \
		-exec ${STRIP_CMD} {} +
	${LN} -fs ../${DATADIR_REL}/renpy.py \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDATA}" ${STAGEDIR}${DATADIR} \
		"! -name *.orig ! -name *.bak \
		 ! -name saves ! -name log.txt")
	${CHMOD} +x ${STAGEDIR}${DATADIR}/renpy.py

post-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		. ${STAGEDIR}${DOCSDIR} \
		"! -name *.orig ! -name *.bak")

.include <bsd.port.mk>
