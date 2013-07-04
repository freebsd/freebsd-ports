# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	entangle
DISTVERSION=	0.5.1
CATEGORIES=	graphics
MASTER_SITES=	http://entangle-photo.org/download/sources/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Digital camera tethered control and capture program

LICENSE=	GPLv3

LIB_DEPENDS=	gphoto2:${PORTSDIR}/graphics/libgphoto2 \
		lcms:${PORTSDIR}/graphics/lcms \
		gexiv2:${PORTSDIR}/graphics/gexiv2 \
		raw_r:${PORTSDIR}/graphics/libraw \
		peas:${PORTSDIR}/devel/libpeas

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk30

# XXX: it would be nice if one day this option would be passed automatically
# to configure scripts that support it :)
.if defined(BATCH) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS=	--disable-silent-rules
.endif

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		${PORTNAME}.1

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext	
NLS_CONFIGURE_OFF=	--disable-nls

post-patch:
	@${REINPLACE_CMD} -e '/checking for GUDEV/,+93d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,_udev,,' \
		${WRKSRC}/src/backend/entangle-camera-list.c

.include <bsd.port.mk>
