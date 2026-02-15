PORTNAME=	glaxnimate
xDISTVERSIONPREFIX=	v
DISTVERSION=	0.5.80
MASTER_SITES=	https://download.kde.org/unstable/glaxnimate/0.5.80/
CATEGORIES=	graphics

xPATCH_SITES=	https://gitlab.com/${PORTNAME}/${PORTNAME}/-/commit/
xPATCHFILES+=	6f312a0b93208255b2903f6d3105cc36cfc6b6c7.patch:-p1 # Fix build with Qt 6.5.x

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple vector animation program
WWW=		https://invent.kde.org/graphics/glaxnimate \
		https://gitlab.com/mattbas/glaxnimate \
		https://github.com/KDE/glaxnimate \
		https://gitlab.com/mattbas/glaxnimate/

#BROKEN=		Does not build with ffmpeg > 6

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv7=	lrelease coredumps, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276285

BUILD_DEPENDS=	pip:devel/py-pip@${PY_FLAVOR}
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libpotrace.so:graphics/libpotrace

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-tools gl kde:6 libarchive \
		python qt:6 tar:xz
USE_GL=		gl
USE_QT=		base svg tools
USE_KDE=	archive breeze-icons colorscheme completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes widgetsaddons xmlgui \
		ecm:build

CMAKE_ON=	BUILD_WITH_QT6
CMAKE_OFF=	BUILD_WITH_QT5

CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD} \
		-DQT_MAJOR_VERSION=6
#CMAKE_ARGS+= -Wdev --debug-output --trace

ALL_TARGET=	all

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDEBUG}
CXXFLAGS:=	${CXXFLAGS:C/-O([2-9]|[sz]|fast)/-O1/} -fstack-protector-strong -fno-strict-aliasing
.endif

.include <bsd.port.mk>
