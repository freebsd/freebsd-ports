# New ports collection makefile for:	celestia
# Date created:				2002-05-17
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		celestia
PORTVERSION=		1.3.2
CATEGORIES=		astro
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	celestia

MAINTAINER=		trevor@FreeBSD.org
COMMENT=		Scriptable space flight simulator for X

LIB_DEPENDS=		jpeg.9:${PORTSDIR}/graphics/jpeg \
			png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=		yes
PLIST=			${WRKDIR}/plist
PORTDOCS=		AUTHORS CelestiaKeyAssignments.txt ChangeLog \
			coding-standards.html devguide.txt \
			KbdMouseJoyControls.txt README TODO TRANSLATORS
USE_GMAKE=		yes
USE_GL=			yes
USE_GNOME=
USE_REINPLACE=		yes
USE_X_PREFIX=		yes

CONFIGURE_ARGS=		--program-prefix=""
CONFIGURE_ENV=	\
	LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib -lm ${PTHREAD_LIBS}" \
	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}"

OPTIONS=		LUA "Lua support" off \
			GLUT "Glut interface" off \
			GTK "Gtk+ interface" off \
			GNOME "GNOME interface" off \
			KDE "KDE interface" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=			"Does not compile on FreeBSD 4.x"
.endif

.if defined(WITH_LUA)
LIB_DEPENDS+=		lua.5:${PORTSDIR}/lang/lua
CONFIGURE_ARGS+=	--with-lua
.endif

.if defined(WITH_GNOME)
PKGMESSAGE=		${WRKDIR}/message
WITH_GTK=		yes		# GNOME requires GTK+
USE_GNOME+=		libgnomeui
CONFIGURE_ARGS+=	--with-gnome
GCONF_SCHEMAS=		celestia.schemas
.endif

.if defined(WITH_GTK)
USE_GNOME+=		gnomehack gnomeprefix gtk20
LIB_DEPENDS+=		gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUB+=		DATADIR="share/gnome/celestia"
.else
PLIST_SUB+=		DATADIR="share/celestia"
.endif

.if defined(WITH_KDE)
USE_KDELIBS_VER=	3
CONFIGURE_ARGS+=	--with-kde
# KDE_LIBS_VER is defined after including bsd.port.pre.mk, so we need
# to include bsd.kde.mk manually.
.include "${PORTSDIR}/Mk/bsd.kde.mk"
.endif

.if !defined(WITH_KDE) && !defined(WITH_GTK) && !defined(WITH_GNOME)
WITH_GLUT=		yes		# an UI is required, fallback to Glut
.endif

.if defined(WITH_GLUT)
CONFIGURE_ARGS+=	--with-glut
.endif

.if defined(WITH_GTK) || defined(WITH_GLUT)
# libglut is only required for Glut and GTK+ interfaces
LIB_DEPENDS+=		glut:${PORTSDIR}/graphics/libglut
.endif

pre-patch:
	@${REINPLACE_CMD} -e \
		's|-O2||g; \
		 s|-Wall||g; \
		 s|-ffast-math||g; \
		 s|-fexpensive-optimizations||g; \
		 s|"x" = "y"|"x" = "x"|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|COPYING||g' ${WRKSRC}/Makefile.in
.if !defined(WITH_GNOME)
	@${REINPLACE_CMD} -e \
		's|\(install-pkgdataDATA\) install-schemasDATA|\1|; \
		 s|\$$(DESTDIR)\$$(schemasdir)||' \
		${WRKSRC}/src/celestia/gtk/data/Makefile.in
.endif

pre-install:
	@${RM} -f ${PLIST}
.if defined(WITH_GNOME)
	@${ECHO_CMD} "The GConf daemon must be restarted with the commands:" \
		>> ${PKGMESSAGE}
	@${ECHO_CMD} "gconftool-2 --shutdown && gconftool-2 --spawn" \
		>> ${PKGMESSAGE}
	@${ECHO_CMD} share/gnome/applications/celestia.desktop >> ${PLIST}
	@${ECHO_CMD} share/gnome/pixmaps/celestia.png >> ${PLIST}
.endif
.for ii in bin/celestia %%DATADIR%%/celestia.png %%DATADIR%%/controls.txt
	@${ECHO_CMD} ${ii} >> ${PLIST}
.endfor
	@${FIND} ${WRKSRC}/data/ -name '*.???' | \
		${SED} -e "s:^${WRKSRC}/:%%DATADIR%%/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/extras/ -name '*.ssc' | \
		${SED} -e "s:^${WRKSRC}/:%%DATADIR%%/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/fonts/ -name '*.txf' | \
		${SED} -e "s:^${WRKSRC}/:%%DATADIR%%/:g" >> ${PLIST}
.for ii in celestia.cfg demo.cel guide.cel start.cel
	@${ECHO_CMD} %%DATADIR%%/${ii} >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
	@${FIND} ${WRKSRC}/manual/ -name '*.???*' | \
		${SED} -e "s:^${WRKSRC}/:%%DATADIR%%/:g" >> ${PLIST}
.endif
	@${FIND} ${WRKSRC}/models/ -name '*.???*' | \
		${SED} -e "s:^${WRKSRC}/:%%DATADIR%%/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/shaders/ -name '*.fp' | \
		${SED} -e "s:^${WRKSRC}/:%%DATADIR%%/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/shaders/ -name '*.vp' | \
		${SED} -e "s:^${WRKSRC}/:%%DATADIR%%/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/textures/ -name '*.jpg' -o -name '*.png'| \
		${SED} -e "s:^${WRKSRC}/:%%DATADIR%%/:g" >> ${PLIST}
.for ii in /data /extras /fonts /manual /models /shaders \
	/textures/hires /textures/lores /textures/medres /textures /
	@${ECHO_CMD} @dirrm %%DATADIR%%${ii} >> ${PLIST}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif
.if defined(WITH_GNOME)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
