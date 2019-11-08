# Created by: Denis Barov <dindin@dindin.ru>
# $FreeBSD$

PORTNAME=	lensfun
PORTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library for fixing lens geometry distortions

LICENSE=	GPLv3 LGPL3 CC-BY-SA-3.0 PD
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=		${WRKSRC}/docs/gpl-3.0.txt
LICENSE_FILE_LGPL3=		${WRKSRC}/docs/lgpl-3.0.txt
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/docs/cc-by-sa-3.0.txt

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake gettext-runtime gnome pathfix pkgconfig shebangfix
SHEBANG_FILES=	apps/lensfun-update-data apps/lensfun-add-adapter
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DBUILD_AUXFUN:BOOL=ON
MAKE_ENV+=	PYTHONDONTWRITEBYTECODE= PYTHONOPTIMIZE=
PLIST_SUB+=	PYTHON_SUFFIX=${PYTHON_SUFFIX}

OPTIONS_DEFINE=	SIMD PYHELPERS
OPTIONS_DEFAULT=	SIMD PYHELPERS
OPTIONS_SUB=	yes
PYHELPERS_DESC=	Install database helper scripts (need Python 3)

SIMD_CMAKE_OFF=	-DBUILD_FOR_SSE:BOOL=OFF -DBUILD_FOR_SSE2:BOOL=OFF

PYHELPERS_CMAKE_ON=	-DSTAGEDIR:STRING=${STAGEDIR} -DPYTHON:STRING=${PYTHON_CMD}
PYHELPERS_CMAKE_OFF=	-DINSTALL_HELPER_SCRIPTS:BOOL=OFF -DPYTHON:STRING=IGNORE
PYHELPERS_USES=		python:3.4+

post-patch:
# Fix the build against Clang 6.0.0
	@${REINPLACE_CMD} -e '/%%/s,R_BX, & ,' ${WRKSRC}/libs/lensfun/cpuid.cpp

.include <bsd.port.mk>
