# New ports collection makefile for:	genius
# Version required:			0.4.0
# Date created:				1 May 1999
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=	genius-0.4.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://ftp.5z.com/pub/genius/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		art_lgpl.1:${PORTSDIR}/x11/gnomelibs \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		esd.1:${PORTSDIR}/audio/esound \
		gdk_imlib.3:${PORTSDIR}/graphics/imlib \
		gdk12.1:${PORTSDIR}/x11-toolkits/gtk12 \
		gif.3:${PORTSDIR}/graphics/png \
		glib12.1:${PORTSDIR}/devel/glib12 \
		gmodule12.1:${PORTSDIR}/devel/glib12 \
		gnome.1:${PORTSDIR}/x11/gnomelibs \
		gnomesupport.1:${PORTSDIR}/x11/gnomelibs \
		gnomeui.1:${PORTSDIR}/x11/gnomelibs \
		gtk12.1:${PORTSDIR}/x11-toolkits/gtk12 \
		intl.1:${PORTSDIR}/devel/gettext \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff34

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib12-config" \
		GTK_CONFIG="${X11BASE}/bin/gtk12-config"

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/genius
.for file in AUTHORS COPYING ChangeLog NEWS README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/genius
.endfor
.endif

.include <bsd.port.mk>
