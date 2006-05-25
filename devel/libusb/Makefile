# New ports collection makefile for:	libusb
# Date created:				27 January 2001
# Whom:					John Reynolds <johnjen@reynoldsnet.org>
#
# $FreeBSD$
#

PORTNAME=	libusb
PORTVERSION=	0.1.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	r.c.ladan@gmail.com
COMMENT=	Library giving userland programs access to USB devices

CONFIGURE_ARGS=	--disable-build-docs
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|' ${WRKSRC}/descriptors.c

.include <bsd.port.mk>
