# New ports collection makefile for:   gnomeutils
# Version required:    0.30
# Date created:        03 July 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id$
#

DISTNAME=	gnome-utils-0.30
PKGNAME=        gnomeutils-0.30
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	gnome.0:${PORTSDIR}/x11/gnomelibs \
		gtop.0:${PORTSDIR}/devel/libgtop

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include \
		-I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

MAN1=		gtt.1

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
