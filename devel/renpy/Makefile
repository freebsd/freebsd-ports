# $FreeBSD$

PORTNAME=	renpy
PORTVERSION=	6.99.4
DISTVERSIONSUFFIX=-source
CATEGORIES=	devel games
MASTER_SITES=	http://www.renpy.org/dl/${PORTVERSION}/
#MASTER_SITES+=	GENTOO

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Framework for developing visual-novel type games

LICENSE=	APACHE20 BSD3CLAUSE DejaVu LGPL21 MIT OFL11 ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_DejaVu=	Bitstream Vera and Arev fonts license
LICENSE_FILE_DejaVu=	${WRKSRC}/renpy/common/DejaVuSans.txt
LICENSE_PERMS_DejaVu=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game_sdl2>0:${PORTSDIR}/devel/py-game_sdl2 \
		cython:${PORTSDIR}/lang/cython
LIB_DEPENDS=	libfribidi.so:${PORTSDIR}/converters/fribidi \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libpng.so:${PORTSDIR}/graphics/png \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libfreetype.so:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game_sdl2>0:${PORTSDIR}/devel/py-game_sdl2

# Upstream tends to reroll distfiles before moving under /release/
PORTSCOUT=	site:http://www.renpy.org/dl/release/

USES=		python:2.7 shebangfix tar:bz2
USE_PYTHON=	autoplist distutils
USE_SDL=	sdl2
EXTRACT_AFTER_ARGS=--exclude gen --exclude '*.py[co]'
SHEBANG_FILES=	renpy.py launcher/game/tkaskdir.py
python_OLD_CMD=	/usr/bin/env python
python_CMD=	${PYTHON_CMD}
BUILD_WRKSRC=	${WRKSRC}/module
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKE_ENV+=	RENPY_DEPS_INSTALL="${LOCALBASE}"
PYDISTUTILS_BUILDPATH=${BUILD_WRKSRC}/build/lib.${OPSYS:tl}-${UNAMER}-${ARCH}-${PYTHON_VER}
PORTDATA=	launcher renpy renpy.py templates
PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME}

DESKTOP_ENTRIES="Ren'Py" \
		"" \
		"${DATADIR}/launcher/game/images/logo32.png" \
		"${PORTNAME} %f" \
		"Development;Game;AdventureGame;" \
		""

OPTIONS_DEFAULT=TKINTER
OPTIONS_DEFINE=	DOCS EXAMPLES TKINTER

TKINTER_DESC=	Install Tkinter to allow choosing Projects Directory
TKINTER_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
PORTDATA+=	the_question tutorial
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
		${WRKSRC}/launcher/game/choose_directory.rpy
# Avoid having to add -I/usr/include -L/usr/lib
	@${REINPLACE_CMD} '/library("z")/d' ${BUILD_WRKSRC}/${PYSETUP}

post-build:
	@${PYTHON_CMD} -m compileall -d ${DATADIR} ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall -d ${DATADIR} ${WRKSRC}
# XXX Replace WRKSRC with DATADIR in bytecode
	@(cd ${WRKSRC} && for d in */game templates/*; do \
		${SETENV} HOME=${WRKDIR} \
		PYTHONPATH="${PYTHONPATH}:${PYDISTUTILS_BUILDPATH}" \
		${PYTHON_CMD} ${WRKSRC}/renpy.py $$d compile; \
	done)

add-plist-post: add-empty-dirs
add-empty-dirs:
# Keep images directory in templates, see renpy@d81ea29
	${FIND} ${WRKSRC}/templates -type d ! -name "saves" -empty | \
		${SED} 's,^${WRKSRC},@dir ${DATADIR},' >>${TMPPLIST}

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name \*.so \
		-exec ${STRIP_CMD} {} +
	${LN} -fs ${DATADIR}/renpy.py \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDATA}" ${STAGEDIR}${DATADIR} \
		"! -name *.orig ! -name *.bak \
		 ! -name saves ! -name log.txt")
	${CHMOD} +x ${STAGEDIR}${DATADIR}/renpy.py
	${CHMOD} -R u+w ${STAGEDIR}${DATADIR}/templates
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		. ${STAGEDIR}${DOCSDIR} \
		"! -name *.orig ! -name *.bak")
.endif

.include <bsd.port.mk>
