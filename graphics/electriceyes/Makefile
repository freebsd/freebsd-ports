# New ports collection makefile for:   electriceyes
# Version required:    0.2
# Date created:        21 August 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id$
#

DISTNAME=	ee-0.2
PKGNAME=	electriceyes-0.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	panel_applet\\.0:${PORTSDIR}/x11/gnomecore

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include -I./intl" \
		LIBS="-L${LOCALBASE}/lib -lxpg4"

post-install:
	${MV} ${PREFIX}/bin/ee ${PREFIX}/bin/ElectricEyes

.include <bsd.port.mk>
