# New ports collection makefile for:	foxtrotgps
# Date created:				15 January 2011
# Whom:						crwhipp@gmail.com
#
# $FreeBSD$
#

PORTNAME=	foxtrotgps
PORTVERSION=	1.1.1
CATEGORIES=	astro geography
MASTER_SITES=	http://www.foxtrotgps.org/releases/

MAINTAINER=	crwhipp@gmail.com
COMMENT=	A lightweight opensource gps moving map application

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		exif:${PORTSDIR}/graphics/libexif \
		soup-2.4:${PORTSDIR}/devel/libsoup \
		gps:${PORTSDIR}/astro/gpsd

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes

USE_GNOME=	gtk20 gconf2 libxml2 intltool pkgconfig libglade2
USE_SQLITE=	3
INSTALLS_ICONS=	yes

GCONF_SCHEMAS=	apps_foxtrotgps.schemas

MAN1=	foxtrotgps.1 convert2gpx.1 convert2osm.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/contrib/convert2gpx ${WRKSRC}/contrib/convert2osm
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${LOCALBASE}/bin/python|' ${WRKSRC}/contrib/georss2foxtrotgps-poi

.include <bsd.port.mk>
