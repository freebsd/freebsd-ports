PORTNAME=	lensfun
PORTVERSION=	0.3.95
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library for fixing lens geometry distortions
WWW=		https://lensfun.github.io/

LICENSE=	GPLv3 LGPL3 CC-BY-SA-3.0 PD
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=		${WRKSRC}/docs/gpl-3.0.txt
LICENSE_FILE_LGPL3=		${WRKSRC}/docs/lgpl-3.0.txt
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/docs/cc-by-sa-3.0.txt

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake compiler:c++11-lang gettext-runtime gnome pathfix \
		pkgconfig shebangfix
SHEBANG_FILES=	apps/lensfun-add-adapter apps/lensfun-convert-lcp \
		apps/lensfun-update-data
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DBUILD_AUXFUN:BOOL=ON -DBUILD_LENSTOOL:BOOL=ON
MAKE_ENV+=	PYTHONDONTWRITEBYTECODE= PYTHONOPTIMIZE=

OPTIONS_DEFINE=	SIMD PYHELPERS
OPTIONS_DEFAULT=	SIMD PYHELPERS
OPTIONS_SUB=	yes
PYHELPERS_DESC=	Install database helper Python scripts

SIMD_CMAKE_OFF=	-DBUILD_FOR_SSE:BOOL=OFF -DBUILD_FOR_SSE2:BOOL=OFF

PYHELPERS_BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/setuptools/_distutils/core.py:devel/py-setuptools@${PY_FLAVOR}
PYHELPERS_CMAKE_ON=	-DSTAGEDIR:STRING=${STAGEDIR} -DPYTHON:STRING=${PYTHON_CMD}
PYHELPERS_CMAKE_OFF=	-DINSTALL_HELPER_SCRIPTS:BOOL=OFF -DPYTHON:STRING=IGNORE
PYHELPERS_USES=		python

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
CMAKE_ARGS+=	-DBUILD_TESTS:BOOL=ON
.endif

post-patch:
	@${REINPLACE_CMD} -e '/#include <cmath>/ { x; s/^/#include <clocale>/; G; }' \
		${WRKSRC}/tests/test_modifier_coord_centering_old.cpp \
		${WRKSRC}/tests/test_modifier_coord_perspective_correction.cpp \
		${WRKSRC}/tests/test_modifier_coord_perspective_correction_old.cpp \
		${WRKSRC}/tests/test_modifier_coord_tiny_image_old.cpp \
		${WRKSRC}/tests/test_modifier_performance.cpp \
		${WRKSRC}/tests/test_modifier_regression.cpp \
		${WRKSRC}/tests/test_modifier_regression_old.cpp

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
