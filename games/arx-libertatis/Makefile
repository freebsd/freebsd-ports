# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arx-libertatis
PORTVERSION=	1.1.2
CATEGORIES=	games
MASTER_SITES=	http://downloads.sourceforge.net/arx/ \
		http://arx-libertatis.org/files/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform port of Arx Fatalis

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/ARX_PUBLIC_LICENSE.txt

LIB_DEPENDS=	libIL.so:${PORTSDIR}/graphics/devil \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libboost_program_options.so:${PORTSDIR}/devel/boost-libs

USES=		cmake openal tar:xz
USE_SDL=	sdl
USE_GL=		gl
CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR="man" -DDATA_DIR=arx -DSTRICT_USE=ON

SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS CHANGELOG README.md

OPTIONS_DEFINE=	CRASHREPORTER DOCS
CRASHREPORTER_DESC=	Build crash reporter (requires Qt4)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCRASHREPORTER}
USE_QT4=	corelib gui network rcc_build moc_build uic_build qmake_build
CMAKE_ARGS+=	-DBUILD_CRASHREPORTER=ON -DUSE_QT5=OFF
PLIST_SUB+=	CRASHREPORTER=""
.else
CMAKE_ARGS+=	-DBUILD_CRASHREPORTER=OFF
PLIST_SUB+=	CRASHREPORTER="@comment "
.endif

post-patch:
.if ${OSVERSION} >= 1000705
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
