# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arx-libertatis
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://downloads.sourceforge.net/arx/ \
		http://arx-libertatis.org/files/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform port of Arx Fatalis

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/ARX_PUBLIC_LICENSE.txt

LIB_DEPENDS=	libfreetype.so:print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/include/boost/foreach.hpp:devel/boost-libs

USES=		cmake openal tar:xz
USE_SDL=	sdl
USE_GL=		gl glew
CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR="man" -DDATA_DIR=arx -DSTRICT_USE=ON

SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS CHANGELOG README.md

OPTIONS_DEFINE=	CRASHREPORTER DOCS
OPTIONS_SUB=	yes

CRASHREPORTER_DESC=	Build crash reporter (requires Qt4)
CRASHREPORTER_USE=	QT4=corelib,gui,network \
			QT4=rcc_build,moc_build,uic_build,qmake_build
CRASHREPORTER_CMAKE_ON=	-DBUILD_CRASHREPORTER=ON -DUSE_QT5=OFF
CRASHREPORTER_CMAKE_OFF=-DBUILD_CRASHREPORTER=OFF

.include <bsd.port.options.mk>

post-patch:
.if ${OPSYS} == FreeBSD && ((${OSVERSION} >= 1000705 && ${OSVERSION} < 1001503) || (${OSVERSION} >= 1100000 && ${OSVERSION} < 1100046))
# Workaround for clang 3.4 bug: it crashes when debug info is enabled
# See http://llvm.org/bugs/show_bug.cgi?id=19031, http://llvm.org/bugs/show_bug.cgi?id=20893
	@${REINPLACE_CMD} -e '/add_cxxflag.*-g2/ d' ${WRKSRC}/cmake/BuildType.cmake
.endif
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/CMakeLists.txt

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
