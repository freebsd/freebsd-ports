# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	entangle
DISTVERSION=	0.5.3
CATEGORIES=	graphics
MASTER_SITES=	http://entangle-photo.org/download/sources/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Digital camera tethered control and capture program

LICENSE=	GPLv3

LIB_DEPENDS=	libgphoto2.so:${PORTSDIR}/graphics/libgphoto2 \
		liblcms.so:${PORTSDIR}/graphics/lcms \
		libgexiv2.so:${PORTSDIR}/graphics/gexiv2 \
		libraw_r.so:${PORTSDIR}/graphics/libraw \
		libpeas-1.0.so:${PORTSDIR}/devel/libpeas

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk30

# XXX: it would be nice if one day this option would be passed automatically
# to configure scripts that support it :)
.if defined(BATCH) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS=	--disable-silent-rules
.endif

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

post-patch:
	@${REINPLACE_CMD} -e '/checking for GUDEV/,+93d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,_udev,,' \
		${WRKSRC}/src/backend/entangle-camera-list.c

.include <bsd.port.mk>
