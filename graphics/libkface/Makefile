# $FreeBSD$

PORTNAME=	libkface
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	1
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 library for face recognition

NO_STAGE=	yes
.include "${.CURDIR}/../digikam-kde4/Makefile.common"

USES+=		pkgconfig
LIB_DEPENDS=	libopencv_legacy.so:${PORTSDIR}/graphics/opencv
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s|$${LIB_INSTALL_DIR}|libdata|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
