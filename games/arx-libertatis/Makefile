# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arx-libertatis
PORTVERSION=	1.1.2
PORTREVISION=	13
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
LLD_UNSAFE=	yes
CMAKE_ARGS=	-DDATA_DIR=arx \
		-DSTRICT_USE=ON
CFLAGS_powerpc64+=	-mminimal-toc

SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS CHANGELOG README.md

OPTIONS_DEFINE=	CRASHREPORTER DOCS
OPTIONS_SUB=	yes

CRASHREPORTER_DESC=	Build crash reporter (requires Qt4)
CRASHREPORTER_USES=	qt:4
CRASHREPORTER_USE=	QT=corelib,gui,network \
			QT=rcc_build,moc_build,uic_build,qmake_build
CRASHREPORTER_CMAKE_ON=	-DBUILD_CRASHREPORTER=ON -DUSE_QT5=OFF
CRASHREPORTER_CMAKE_OFF=-DBUILD_CRASHREPORTER=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCRASHREPORTER}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
