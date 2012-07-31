# New ports collection makefile for:	Rawstudio
# Date created:				2008-04-23
# Whom:					Alex Samorukov <samm@os2.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	rawstudio
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://rawstudio.org/files/release/

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Open-source program to read and manipulate RAW photo images

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		lcms.1:${PORTSDIR}/graphics/lcms \
		exiv2.12:${PORTSDIR}/graphics/exiv2 \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		lensfun.2:${PORTSDIR}/graphics/lensfun \
		flickcurl.0:${PORTSDIR}/www/flickcurl \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2
BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20 libxml2 gconf2 desktopfileutils gnomehack
USE_SQLITE=	3
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's, libssl,,' ${WRKSRC}/configure

.include <bsd.port.mk>
