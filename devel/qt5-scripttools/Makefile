PORTNAME=	scripttools
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Script additional components

USES=		compiler:c++11-lang perl5 qmake qt-dist:5,script
USE_PERL5=	build
USE_QT=		core gui script widgets buildtools:build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/src/${PORTNAME}

# Source version from qt-dist.mk
QT5_VERSION=	${_KDE_script_VERSION}

# Link in QtScript port
_QT5_ADDITIONAL_LINK=	script

# Fix version mismatches for CMake
post-configure:
	@${REINPLACE_CMD} -e '/${QT5_VERSION} $${_Qt5ScriptTools_FIND_VERSION_EXACT}/s|${QT5_VERSION}|'"$$(${MAKE} -C ../qt5-core -VQT5_VERSION)"'|' \
		${WRKSRC}/lib/cmake/Qt5ScriptTools/Qt5ScriptToolsConfig.cmake

.include <bsd.port.mk>
