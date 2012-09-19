# New ports collection makefile for:	libkface
# Date created:				2012-05-12
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libkface
PORTVERSION=	${DIGIKAM_VER}
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 library for face recognition

.include "${.CURDIR}/../digikam-kde4/Makefile.common"

LIB_DEPENDS=	opencv_legacy:${PORTSDIR}/graphics/opencv

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s|$${LIB_INSTALL_DIR}|libdata|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
