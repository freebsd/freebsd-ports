PORTNAME=	jkqtplotter
DISTVERSION=	5.0.0 # not tagged yet, see https://github.com/jkriege2/JKQtPlotter/issues/155
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extensive Qt plotter framework
WWW=		https://github.com/jkriege2/JKQtPlotter

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	qt6 qt5
FLAVOR?=	qt6

QT_VER=		${FLAVOR:S/qt//}

USES=		cmake compiler:c++11-lang dos2unix gl qt:${QT_VER}
USE_GL=		opengl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jkriege2
GH_PROJECT=	JKQtPlotter
GH_TAGNAME=	ff89c530

DOS2UNIX_FILES=	CMakeLists.txt \
		lib/jkqtmathtext/CMakeLists.txt \
		lib/jkqtplotter/graphs/jkqtpbarchart.h \
		lib/jkqtplotter/graphs/jkqtpcontour.h \
		lib/jkqtplotter/graphs/jkqtpfilledcurve.h \
		lib/jkqtplotter/graphs/jkqtpimpulses.h \
		lib/jkqtplotter/graphs/jkqtprange.h \
		lib/jkqtplotter/graphs/jkqtpscatter.h \
		lib/jkqtplotter/graphs/jkqtpspecialline.h

_USE_QT_qt5=	core gui opengl printsupport svg testlib xml widgets qmake:build buildtools:build
_USE_QT_qt6=	base svg tools:build
USE_QT=		${_USE_QT_${FLAVOR}}

CMAKE_ON=	JKQtPlotter_BUILD_SHARED_LIBS
CMAKE_OFF=	JKQtPlotter_BUILD_STATIC_LIBS \
		JKQtPlotter_BUILD_TOOLS \
		JKQtPlotter_BUILD_TESTS \
		JKQtPlotter_BUILD_EXAMPLES \
		JKQtPlotter_BUILD_DECORATE_LIBNAMES_WITH_BUILDTYPE

CMAKE_ARGS=	-DCMAKE_INSTALL_INCLUDEDIR=include/qt${QT_VER}

PLIST_SUB=	CMAKE_BUILD_TYPE=release \
		QT_VER=${QT_VER}

OPTIONS_DEFINE=	EXAMPLES

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${QT_VER}
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e 's|NAMES Qt6 Qt5|NAMES Qt${QT_VER}|g' \
		${WRKSRC}/cmake/jkqtplotter_common_qtsettings.cmake

post-install-EXAMPLES-on:
	@cd ${FILESDIR}/examples && \
		${COPYTREE_SHARE} all-in-tabs ${STAGEDIR}${EXAMPLESDIR} && \
		${COPYTREE_SHARE} simple-plot ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
