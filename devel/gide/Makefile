# New ports collection makefile for:	gIDE
# Version required:			0.1.1
# Date created:				29 Jul 1998
# Whom:					rom
#
# $Id: Makefile,v 1.22 1999/05/30 03:36:55 steve Exp $
#

DISTNAME= 	gIDE-0.1.1
PKGNAME= 	gide-0.1.1
CATEGORIES=	devel gnome
MASTER_SITES=	http://gide.gdev.net/ \
		http://gide.pn.org/

MAINTAINER=	rom_glsa@ein-hashofet.co.il

LIB_DEPENDS=	gnomeui.2:${PORTSDIR}/x11/gnomelibs \
		guile.4:${PORTSDIR}/lang/guile

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

FETCH_BEFORE_ARGS=	-b

USE_X_PREFIX=   yes
USE_GMAKE= 	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gide.1 gdbio.1

pre-install:
	@${MKDIR} ${PREFIX}/share/gnome/gIDE/extra

.include <bsd.port.mk>
