# $FreeBSD$

PORTNAME=	phantomjs
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://bitbucket.org/ariya/phantomjs/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Minimalistic, headless, WebKit-based, JavaScript-driven tool

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	bash:shells/bash \
		python:lang/python
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libicui18n.so:devel/icu \
		libpng.so:graphics/png

PROJECTHOST=	phantomjs
USES=		bison:build compiler gmake gperf jpeg perl5 pkgconfig python:build zip
USE_PERL5=	build
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_FILES=	bin/phantomjs
#PATCH_DEBUG=	yes
NO_CCACHE=	yes

# NOTE:
#   build.sh --qtwebkit=system requires Qt 5.3.x.  We cannot use it.

# qmake.conf detection is in src/qt/qtbase/configure script.
SPEC=	${WRKSRC}/src/qt/qtbase/mkspecs
post-extract:
	cd ${SPEC} && ${CP} -r freebsd-g++46 freebsd-g++48
	cd ${SPEC} && ${CP} -r freebsd-g++46 freebsd-g++49
	cd ${SPEC} && ${REINPLACE_CMD} -e 's|46|48|' freebsd-g++48/qmake.conf
	cd ${SPEC} && ${REINPLACE_CMD} -e 's|46|49|' freebsd-g++49/qmake.conf
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

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not link on sparc64
.endif

.include <bsd.port.post.mk>
