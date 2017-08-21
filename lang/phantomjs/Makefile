# $FreeBSD$

PORTNAME=	phantomjs
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Minimalistic, headless, WebKit-based, JavaScript-driven tool

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	bash:shells/bash \
		python:lang/python
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libicui18n.so:devel/icu \
		libpng.so:graphics/png

BROKEN_powerpc64=	fails to build: g++48: not found
BROKEN_sparc64=		does not link on sparc64
NOT_FOR_ARCHS=		armv6
NOT_FOR_ARCHS_REASON=	Platform.h: Not supported ARM architecture

USES=		bison:build compiler:c++11-lang gmake gperf jpeg perl5 pkgconfig python:build ssl sqlite
USE_GNOME+=	libxml2
USE_PERL5=	build
USE_RUBY=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ariya
GH_TUPLE=	Vitallium:phantomjs-3rdparty-win:19051aa:msvc2013/src/qt/3rdparty \
		Vitallium:qtbase:b5cc008:qtbase/src/qt/qtbase \
		Vitallium:qtwebkit:e7b7433:qtwebkit/src/qt/qtwebkit
RUBY_NO_RUN_DEPENDS=	yes
PLIST_FILES=	bin/phantomjs
NO_CCACHE=	yes

OPTIONS_DEFINE=	X11
X11_USE=	XORG=x11

.include <bsd.port.options.mk>

# qmake.conf detection is in src/qt/qtbase/configure script.
SPEC=	${WRKSRC}/src/qt/qtbase/mkspecs
post-extract:
	${MKDIR} ${SPEC}/freebsd-clang
	cd ${SPEC} && ${SED} -e 's|\.\./\.\./|../|g' unsupported/freebsd-clang/qmake.conf > freebsd-clang/qmake.conf
	cd ${SPEC} && ${SED} -e 's|\.\./\.\./|../|g' unsupported/freebsd-clang/qplatformdefs.h > freebsd-clang/qplatformdefs.h
	${MKDIR} ${WRKSRC}/src/qt/qtbase/.git
	${MKDIR} ${WRKSRC}/src/qt/qtwebkit/.git
	${RM} ${WRKSRC}/src/qt/qtwebkit/Source/WebCore/DerivedSources.cpp

_ENV=	CC=${CC} CXX=${CXX} GMAKE=${GMAKE} OSTYPE=freebsd MAKEFLAGS=
_BLD=	${PYTHON_CMD} build.py --jobs ${MAKE_JOBS_NUMBER} --confirm
do-build:
.if defined(_PHANTOMJS_USE_QT_SYSTEM)
	cd ${WRKSRC} && ${SETENV} ${_ENV} PATH=${PATH}:${QT_BINDIR} ${_BLD} --qt=system --qtwebkit=system
.else
	cd ${WRKSRC} && ${SETENV} ${_ENV} PATH=${PATH} ${_BLD}
.endif

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bin/phantomjs ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
