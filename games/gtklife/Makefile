# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	gtklife
PORTVERSION=	5.1
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://ironphoenix.org/tril/gtklife/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ implementation of Conways Game of Life

LICENSE=	GPLv2

WANT_GNOME=	yes
INSTALLS_ICONS=	yes
USES=		gmake
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}" docdir="${DOCSDIR}"

PORTDATA=	*
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtklife ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && \
	${FIND} ${DATA_SUBDIRS} -type d ! -empty -exec ${MKDIR} "${STAGEDIR}${DATADIR}/{}" \; && \
	${FIND} ${DATA_SUBDIRS} ! -type d -exec ${INSTALL_DATA} {} "${STAGEDIR}${DATADIR}/{}" \;
.for s in ${ICON_SIZES}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKSRC}/icon_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/gtklife.png
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
