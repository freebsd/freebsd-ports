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

LIB_DEPENDS=	gnomeui.3:${PORTSDIR}/x11/gnomelibs

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
