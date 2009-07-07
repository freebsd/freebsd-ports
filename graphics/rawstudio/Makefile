# New ports collection makefile for:	rawstudio
# Date created:		2008-04-23
# Whom:			Alex Samorukov <samm@os2.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	rawstudio
PORTVERSION=	1.2
CATEGORIES=	graphics
MASTER_SITES=	http://rawstudio.org/files/release/

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Rawstudio is an open-source program to read and manipulate RAW images

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms \
		exiv2.7:${PORTSDIR}/graphics/exiv2 \
		dbus-1.3:${PORTSDIR}/devel/dbus

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GETTEXT=	yes
USE_GNOME=	gtk20 libxml2 gconf2

.include <bsd.port.mk>
