PORTNAME=	script
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4-compatible scripting module

USES=		compiler:c++11-lang perl5 qmake qt-dist:5,script
USE_PERL5=	extract
USE_QT=		core buildtools:build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
# Keep make(1) from descending into src/script/obj/ (qmake:outsource
# doesn't work).
MAKE_ENV=	MAKEOBJDIR=.

# Source version from qt-dist.mk
QT5_VERSION=	${_KDE_script_VERSION}

post-patch:
	@${REINPLACE_CMD} -e '/scripttools/ d' \
		${WRKSRC}/src/src.pro

# Fix version mismatches for CMake
post-configure:
	@${REINPLACE_CMD} -e '/${QT5_VERSION} $${_Qt5Script_FIND_VERSION_EXACT}/s|${QT5_VERSION}|'"$$(${MAKE} -C ../qt5-core -VQT5_VERSION)"'|' \
		${WRKSRC}/lib/cmake/Qt5Script/Qt5ScriptConfig.cmake

.include <bsd.port.mk>
