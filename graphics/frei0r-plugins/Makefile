# $FreeBSD$

PORTREVISION=	1
PKGNAMESUFFIX=	-plugins

COMMENT=	Frei0r meta-port

RUN_DEPENDS=	${LOCALBASE}/include/frei0r.h:graphics/frei0r

USES=	metaport

MASTERDIR=	${.CURDIR}/../frei0r
PLIST=		${WRKDIR}/PLIST

BUILDING_FREI0R_METAPORT=	yes

OPTIONS_DEFINE=	GAVL OPENCV
OPTIONS_DEFAULT=	GAVL OPENCV
GAVL_DESC=	Install gavl plugins
GAVL_RUN_DEPENDS=	${LOCALBASE}/lib/frei0r-1/rgbparade.so:graphics/frei0r-plugins-gavl
OPENCV_DESC=	Install OpenCV plugins
OPENCV_RUN_DEPENDS=	${LOCALBASE}/lib/frei0r-1/facedetect.so:graphics/frei0r-plugins-opencv

.include "${MASTERDIR}/Makefile"

.include <bsd.port.mk>
