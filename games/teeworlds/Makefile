# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	teeworlds
PORTVERSION=	0.6.5
CATEGORIES=	games
MASTER_SITES=	https://downloads.teeworlds.com/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Platform game featuring buggers equipped with weapons

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cmake cpe pkgconfig python
CPE_VERSION=	${PORTVERSION:C/^0\.//}
CMAKE_ARGS=	-DPYTHON_EXECUTABLE="${PYTHON_CMD}"

PLIST_FILES=	bin/${PORTNAME}_srv
PORTDATA=	*

OPTIONS_DEFINE=		CLIENT
OPTIONS_DEFAULT=	CLIENT

CLIENT_DESC=		Build game client
CLIENT_CMAKE_BOOL=	CLIENT
CLIENT_USES=		gl
CLIENT_USE=		GL=gl,glu XORG=x11 SDL=sdl
CLIENT_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libwavpack.so:audio/wavpack \
			libpnglite.so:graphics/pnglite
CLIENT_PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${RM} -r ${WRKSRC}/src/engine/external/wavpack
	@${RM} -r ${WRKSRC}/src/engine/external/pnglite
	@${RM} -r ${WRKSRC}/src/engine/external/zlib

post-patch:
	@${REINPLACE_CMD} -e '/find_package.*Git/ d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|engine/external/pnglite/pnglite.h|pnglite.h|' \
		${WRKSRC}/src/engine/client/*.cpp \
		${WRKSRC}/src/tools/*.cpp

post-patch-CLIENT-off:
	@${REINPLACE_CMD} -e '/find_package.*Pnglite/ d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/find_package.*Wavpack/ d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/find_package.*SDL/ d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/find_package.*Freetype/ d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/find_package.*OpenGL/ d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/find_package.*X11/ d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
