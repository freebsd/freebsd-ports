# New ports collection makefile for:	libticables2
# Date created:		11 October 2006
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticables2
PORTVERSION=	1.0.2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtktiemu
DISTNAME=	${PORTNAME}-20061030

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI calculator link cables library

LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb

WRKSRC=		${WRKDIR}/libticables

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack pkgconfig
USE_LDCONFIG=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"\
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|#include "linux/link_dev.c"||' \
		${WRKSRC}/src/link_slv.c
	@${REINPLACE_CMD} -e 's|<stdint\.h>|"stdints1.h"|' \
		${WRKSRC}/src/linux/ioports.c
	@${REINPLACE_CMD} -e 's|return usb_probe_devices2|return usb_probe_devices1|' \
		${WRKSRC}/src/linux/link_slv.c

.include <bsd.port.post.mk>
