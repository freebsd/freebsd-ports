# $FreeBSD$

PORTNAME=	phantomjs
PORTVERSION=	2.0.0
PORTREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	https://bitbucket.org/ariya/phantomjs/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Minimalistic, headless, WebKit-based, JavaScript-driven tool

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	bash:shells/bash \
		python:lang/python
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libicui18n.so:devel/icu \
		libpng.so:graphics/png

BROKEN_sparc64=		does not link on sparc64
BROKEN_FreeBSD_9_i386=	does not build

USES=		bison:build compiler:c++11-lang gmake gperf jpeg perl5 pkgconfig python:build zip
USE_PERL5=	build
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_FILES=	bin/phantomjs
#PATCH_DEBUG=	yes
NO_CCACHE=	yes

OPTIONS_DEFINE=	X11
X11_USE=	XORG=x11

.include <bsd.port.options.mk>

# NOTE:
#   build.sh --qtwebkit=system requires Qt 5.3.x.  We cannot use it.

# qmake.conf detection is in src/qt/qtbase/configure script.
SPEC=	${WRKSRC}/src/qt/qtbase/mkspecs
post-extract:
	${MKDIR} ${SPEC}/freebsd-clang
	cd ${SPEC} && ${SED} -e 's|\.\./\.\./|../|g' unsupported/freebsd-clang/qmake.conf > freebsd-clang/qmake.conf
	cd ${SPEC} && ${SED} -e 's|\.\./\.\./|../|g' unsupported/freebsd-clang/qplatformdefs.h > freebsd-clang/qplatformdefs.h

_ENV=	CC=${CC} CXX=${CXX} GMAKE=${GMAKE} OSTYPE=freebsd MAKEFLAGS=
#_ENV+=	CFLAGS="-g -pipe"
_BLD=	bash -x build.sh --jobs ${MAKE_JOBS_NUMBER} --confirm
do-build:
.if defined(_PHANTOMJS_USE_QT_SYSTEM)
	cd ${WRKSRC} && ${SETENV} ${_ENV} PATH=${PATH}:${QT_BINDIR} ${_BLD} --qt=system --qtwebkit=system
.else
	cd ${WRKSRC} && ${SETENV} ${_ENV} PATH=${PATH} ${_BLD} --qt-config '-no-pch'
.endif

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bin/phantomjs ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
