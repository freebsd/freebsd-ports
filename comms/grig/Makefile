# New ports collection makefile for:	grig
# Date created:				2004-01-22
# Whom:					Matt Dawson <matt@mattsnetwork.co.uk>
#
# $FreeBSD$

PORTNAME=	grig
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	groundstation

MAINTAINER=	matt@mattsnetwork.co.uk
COMMENT=	Amateur Radio control front-end

LIB_DEPENDS=	hamlib:${PORTSDIR}/comms/hamlib

USE_X_PREFIX=	yes
USE_GNOME=	gconf gtk12 gnomecanvas
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--disable-nls	# nls not supported yet
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|GCONF_LIBS="`|GCONF_LIBS="-lgconf-gtk-1 `|' ${WRKSRC}/configure

.include <bsd.port.mk>
