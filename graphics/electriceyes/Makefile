# New ports collection makefile for:   electriceyes
# Version required:    0.3
# Date created:        21 August 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.2 1998/09/15 10:50:56 asami Exp $
#

DISTNAME=	ee-0.3
PKGNAME=	electriceyes-0.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	gnome.0:${PORTSDIR}/x11/gnomelibs

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include \
		-I${LOCALBASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

post-install:
	${MV} ${PREFIX}/bin/ee ${PREFIX}/bin/ElectricEyes

.include <bsd.port.mk>
