# $FreeBSD$

PORTNAME=	openage
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0-1262
DISTVERSIONSUFFIX=	-ga554ab49
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Free engine clone of the Genie Engine

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/legal/GPLv3

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libopusfile.so:audio/opusfile \
		libpng16.so:graphics/png \
		libnyan.so:lang/nyan
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}

USES=		cmake compiler:c++17-lang python:3.4+ qt:5 shebangfix
SHEBANG_FILES=	configure run.py buildsystem/cythonize.py
USE_GITHUB=	yes
GH_ACCOUNT=	SFTtech
USE_SDL=	image2 sdl2
USE_GL=		gl glu
USE_QT=		core declarative gui network buildtools_build qmake_build
USE_PYTHON=	cython
USE_LDCONFIG=	yes

CMAKE_OFF=	WANT_BACKTRACE WANT_GPERFTOOLS_PROFILER WANT_INOTIFY
CMAKE_ARGS=	-DGLOBAL_CONFIG_DIR:STRING=${ETCDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/env python3|${PYTHON_CMD}|' ${WRKSRC}/buildsystem/modules/FindPython.cmake

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/openage
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg

.include <bsd.port.mk>
