# New ports collection makefile for:	gedit
# Version required:			0.5.4
# Date created:				4 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		gedit-0.5.4
CATEGORIES=		editors gnome
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			http://gedit.pn.org/ \
			http://reviewboard.com/gedit/ \
			ftp://reviewboard.com/pub/gedit/
MASTER_SITE_SUBDIR=	X11/gtkbuffet/apps/gedit

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		art_lgpl.2:${PORTSDIR}/x11/gnomelibs \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		esd.1:${PORTSDIR}/audio/esound \
		gdk_imlib.4:${PORTSDIR}/graphics/imlib \
		gdk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gif.3:${PORTSDIR}/graphics/png \
		glib12.2:${PORTSDIR}/devel/glib12 \
		gmodule12.2:${PORTSDIR}/devel/glib12 \
		gnome.2:${PORTSDIR}/x11/gnomelibs \
		gnomesupport.2:${PORTSDIR}/x11/gnomelibs \
		gnomeui.2:${PORTSDIR}/x11/gnomelibs \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		intl.1:${PORTSDIR}/devel/gettext \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE} \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib12-config" \
		GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gedit.1

post-install:
	@ ${MKDIR} ${PREFIX}/share/gnome/apps/Applications
	@ ${MKDIR} ${PREFIX}/share/gnome/help/gedit
	@ ${MKDIR} ${PREFIX}/share/gnome/help/gedit/C
	@ ${MKDIR} ${PREFIX}/share/gnome/help/gedit/no
	@ ${MV} ${PREFIX}/share/gnome/gnome/apps/Applications/gedit.desktop ${PREFIX}/share/gnome/apps/Applications
	@ ${MV} ${PREFIX}/share/gnome/gnome/help/gedit/C/index.html ${PREFIX}/share/gnome/help/gedit/C
	@ ${MV} ${PREFIX}/share/gnome/gnome/help/gedit/C/topic.dat ${PREFIX}/share/gnome/help/gedit/C
	@ ${MV} ${PREFIX}/share/gnome/gnome/help/gedit/no/index.html ${PREFIX}/share/gnome/help/gedit/no
	@ ${MV} ${PREFIX}/share/gnome/gnome/help/gedit/no/topic.dat ${PREFIX}/share/gnome/help/gedit/no
	@ ${RMDIR} ${PREFIX}/share/gnome/gnome/apps/Applications
	@ ${RMDIR} ${PREFIX}/share/gnome/gnome/apps
	@ ${RMDIR} ${PREFIX}/share/gnome/gnome/help/gedit/C
	@ ${RMDIR} ${PREFIX}/share/gnome/gnome/help/gedit/no
	@ ${RMDIR} ${PREFIX}/share/gnome/gnome/help/gedit
	@ ${RMDIR} ${PREFIX}/share/gnome/gnome/help
	@ ${RMDIR} ${PREFIX}/share/gnome/gnome
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/gedit
.for file in AUTHORS COPYING ChangeLog FAQ INSTALL KNOWNBUGS README README.plugins THANKS TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gedit
.endfor
.endif

.include <bsd.port.mk>
