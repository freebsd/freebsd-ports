# New ports collection makefile for:	gnomeutils
# Version required:			0.99.5
# Date created:				03 July 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.5 1999/01/27 08:31:51 fenner Exp $
#

DISTNAME=	gnome-utils-0.99.5
PKGNAME=	gnomeutils-0.99.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	gnome-utils

MAINTAINER=	nacai@iname.com

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

MAN1=		gtt.1

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
