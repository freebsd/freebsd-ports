# New ports collection makefile for:	kpuzzle
# Date created:				2000-11-04
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		kpuzzle
PORTVERSION=		0.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	unstable/apps/games

MAINTAINER=	trevor@FreeBSD.org

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
		
LIB_DEPENDS=	kde-qt-addon.4:${PORTSDIR}/x11-toolkits/kde-qt-addon \
		kdecore.3:${PORTSDIR}/x11/kdelibs11

BROKEN=		"kde-qt-addon was removed"

GNU_AUTOCONF=	yes
USE_AUTOMAKE=	yes
USE_BZIP2=	yes
#USE_X_PREFIX=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-extra-includes="${LOCALBASE}/include/" \
		--with-qt-includes="${QTDIR}/include/X11/qt/" \
		--enable-debug
CONFIGURE_ENV+=	CPPFLAGS="-I${X11BASE}/include -I${X11BASE}/include/X11/qt -I${PREFIX}/include" \
		KDEDIR=${LOCALBASE} \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		MOC=${X11BASE}/bin/moc \
		QTDIR=${X11BASE}
MAKE_ENV+=	CPPFLAGS="-I${X11BASE}/include -I${X11BASE}/include/X11/qt -I${PREFIX}/include" \
		KDEDIR=${LOCALBASE} \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		MOC=${X11BASE}/bin/moc \
		QTDIR=${X11BASE}
PLIST=		${WRKDIR}/pkg-plist

do-patch:
	${PERL} -pi -e "s:/default/:/en/:g" ${WRKSRC}/kpuzzle/doc/Makefile.am
	${PERL} -pi -e "s:lkdecore -lqt:lkdecore -lkde-qt-addon -lqt:g" ${WRKSRC}/kpuzzle/doc/Makefile.am

do-configure:
	cd ${WRKSRC} && ${SETENV} KDEDIR=${LOCALBASE} PREFIX=${X11BASE} ./configure \
	--with-extra-includes=${LOCALBASE}/include \
	--with-qt-includes=${X11BASE}/include/X11/qt

post-configure:
	${PERL} -pi -e "s:MOC = /usr:MOC = ${X11BASE}:g" `find ${WRKSRC}/kpuzzle -name Makefile`

pre-install:
	${RM} -f ${PLIST}
	cd ${WRKSRC}/kpuzzle/pics/; \
	for i in *.xpm *.bmp; do \
		${ECHO} share/apps/kpuzzle/data/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/kpuzzle/levels/; \
	for i in *.bmp; do \
		${ECHO} share/apps/kpuzzle/levels/$${i} >> ${PLIST}; \
	done
	${ECHO} share/applnk/Games/kpuzzle.kdelnk >> ${PLIST}
	${ECHO} share/icons/kpuzzle.xpm >> ${PLIST}
	${ECHO} share/icons/mini/mini-kpuzzle.xpm >> ${PLIST}
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/kpuzzle/doc/; \
	for i in *html *gif; do \
		${ECHO} share/doc/HTML/en/kpuzzle/$${i} >> ${PLIST}; \
	done
	${ECHO} @dirrm /share/doc/HTML/en/kpuzzle >> ${PLIST}
.endif
.for i in share/apps/kpuzzle/data share/applnk/Games share/apps/kpuzzle/levels share/apps/kpuzzle
	${ECHO} @dirrm ${i} >> ${PLIST}
.endfor

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/HTML/en/kpuzzle
	${INSTALL_DATA} ${WRKSRC}/kpuzzle/doc/*.html ${PREFIX}/share/doc/HTML/en/kpuzzle
	${INSTALL_DATA} ${WRKSRC}/kpuzzle/doc/scr_1.gif ${PREFIX}/share/doc/HTML/en/kpuzzle
.endif
.for i in share/applnk/Games share/apps/kpuzzle/data share/apps/kpuzzle/levels
	${MKDIR} ${PREFIX}/${i}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/kpuzzle/kpuzzle ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/kpuzzle/pics/*.xpm ${WRKSRC}/kpuzzle/pics/*.bmp ${PREFIX}/share/apps/kpuzzle/data/
	${INSTALL_DATA} ${WRKSRC}/kpuzzle/levels/*.bmp ${PREFIX}/share/apps/kpuzzle/levels/
	${INSTALL_DATA} ${WRKSRC}/kpuzzle/kpuzzle.kdelnk ${PREFIX}/share/applnk/Games
	${INSTALL_DATA} ${WRKSRC}/kpuzzle/kpuzzle.xpm ${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/kpuzzle/mini-kpuzzle.xpm ${PREFIX}/share/icons/mini

.include <bsd.port.mk>
