# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-plugins
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

COMMENT=	Frei0r meta-port

RUN_DEPENDS=	${LOCALBASE}/include/frei0r.h:graphics/frei0r

MASTERDIR=	${.CURDIR}/../frei0r
NO_BUILD=	yes
PLIST=		${WRKDIR}/PLIST


BUILDING_FREI0R_METAPORT=	yes

OPTIONS_DEFINE=	GAVL OPENCV
OPTIONS_DEFAULT=	GAVL OPENCV
GAVL_DESC=	Install gavl plugins
OPENCV_DESC=	Install OpenCV plugins
PATCHDIR=	${.CURDIR}/files

.include "${MASTERDIR}/Makefile"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGAVL}
RUN_DEPENDS+=	${LOCALBASE}/lib/frei0r-1/rgbparade.so:graphics/frei0r-plugins-gavl
.endif

.if ${PORT_OPTIONS:MOPENCV}
RUN_DEPENDS+=	${LOCALBASE}/lib/frei0r-1/facedetect.so:graphics/frei0r-plugins-opencv
.endif

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
