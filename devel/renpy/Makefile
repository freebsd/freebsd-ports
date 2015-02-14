# $FreeBSD$

PORTNAME=	renpy
PORTVERSION=	6.18.3
DISTVERSIONSUFFIX=-source
CATEGORIES=	devel games
MASTER_SITES=	http://www.renpy.org/dl/${PORTVERSION}/ \
		GENTOO/distfiles

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Framework for developing visual-novel type games

LICENSE=	APACHE20 BSD3CLAUSE DejaVu LGPL21 MIT OFL11 ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_DejaVu=	Bitstream Vera and Arev fonts license
LICENSE_FILE_DejaVu=	${WRKSRC}/renpy/common/DejaVuSans.txt
LICENSE_PERMS_DejaVu=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYGAME} \
		cython:${PORTSDIR}/lang/cython
LIB_DEPENDS=	libfribidi.so:${PORTSDIR}/converters/fribidi \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libpng.so:${PORTSDIR}/graphics/png \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libfreetype.so:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${PYGAME}

USES=		python:2.7 shebangfix tar:bz2
USE_PYTHON=	autoplist distutils
USE_SDL=	sdl
SHEBANG_FILES=	renpy.py launcher/game/tkaskdir.py
python_OLD_CMD=	/usr/bin/env python
python_CMD=	${PYTHON_CMD}
BUILD_WRKSRC=	${WRKSRC}/module
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKE_ENV+=	RENPY_DEPS_INSTALL="${LOCALBASE}"
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
		${WRKSRC}/launcher/game/project.rpy
# Avoid having to add -I/usr/include -L/usr/lib
	@${REINPLACE_CMD} '/library("z")/d' ${BUILD_WRKSRC}/${PYSETUP}

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name \*.so \
		-exec ${STRIP_CMD} {} +
	${LN} -fs ${DATADIR}/renpy.py \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDATA}" ${STAGEDIR}${DATADIR} \
		"! -name *.orig ! -name *.bak")
	${CHMOD} +x ${STAGEDIR}${DATADIR}/renpy.py
	${CHMOD} -R u+w ${STAGEDIR}${DATADIR}/templates
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		. ${STAGEDIR}${DOCSDIR} \
		"! -name *.orig ! -name *.bak")
.endif

.include <bsd.port.mk>
