PORTNAME=	frei0r
PORTVERSION=	${FREI0R_VERSION}
CATEGORIES=	graphics
PKGNAMESUFFIX=	-plugins

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	The "meta-port" for frei0r and additional plugins
WWW=		https://frei0r.dyne.org/

RUN_DEPENDS=	frei0r>=${FREI0R_VERSION}:graphics/frei0r

USES=		metaport

DESCR=		${.CURDIR}/../frei0r/pkg-descr

OPTIONS_DEFINE=		CAIRO GAVL OPENCV
OPTIONS_DEFAULT=	CAIRO GAVL OPENCV

CAIRO_DESC=		Install cairo plugins
CAIRO_RUN_DEPENDS=	frei0r-plugins-cairo>=${FREI0R_VERSION}:graphics/frei0r-plugins-cairo
GAVL_DESC=		Install gavl plugins
GAVL_RUN_DEPENDS=	frei0r-plugins-gavl>=${FREI0R_VERSION}:graphics/frei0r-plugins-gavl
OPENCV_DESC=		Install OpenCV plugins
OPENCV_RUN_DEPENDS=	frei0r-plugins-opencv>=${FREI0R_VERSION}:graphics/frei0r-plugins-opencv

.include "${.CURDIR}/../frei0r/version.mk"
.include <bsd.port.mk>
