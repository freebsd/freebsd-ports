# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	gtklife
PORTVERSION=	5.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://ironphoenix.org/tril/gtklife/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	GTK+ implementation of Conway's Game of Life

LICENSE=	GPLv2

WANT_GNOME=	yes
INSTALLS_ICONS=	yes
USES=	gmake
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}" docdir="${DOCSDIR}"

PLIST=		${WRKDIR}/pkg-plist
PLIST_FILES=	bin/gtklife
PLIST_DIRS=	%%DATADIR%%
PORTDOCS=	*

DATA_SUBDIRS=	graphics patterns
ICON_SIZES=	16x16 32x32 48x48

DESKTOP_ENTRIES="GtkLife" \
		"Play Conway's Game of Life" \
		"gtklife" \
		"gtklife" \
		"Game;Simulation;" \
		${STARTUP_NOTIFY}

OPTIONS_DEFINE=	GTK2
GTK2_DESC=	GTK2 gui toolkit support (beta)

MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
MAKE_ARGS+=	gtk2=yes
STARTUP_NOTIFY=	true
.else
USE_GNOME+=	gtk12
STARTUP_NOTIFY=	false
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|' ${WRKSRC}/Makefile

pre-install:
	@cd ${WRKSRC} && >${PLIST} && \
	${FIND} ${DATA_SUBDIRS} ! -type d | ${SORT} \
		| ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} ${DATA_SUBDIRS} -type d ! -empty | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
.for s in ${ICON_SIZES}
	@${ECHO_CMD} "share/icons/hicolor/${s}/apps/gtklife.png" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry share/icons/hicolor/${s}/apps" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry share/icons/hicolor/${s}" >> ${PLIST}
.endfor
	@${ECHO_CMD} "@dirrmtry share/icons/hicolor" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry share/icons" >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtklife ${PREFIX}/bin
	cd ${WRKSRC} && \
	${FIND} ${DATA_SUBDIRS} -type d ! -empty -exec ${MKDIR} "${DATADIR}/{}" \; && \
	${FIND} ${DATA_SUBDIRS} ! -type d -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKSRC}/icon_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/gtklife.png
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
