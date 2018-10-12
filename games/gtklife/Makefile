# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	gtklife
PORTVERSION=	5.2
CATEGORIES=	games
MASTER_SITES=	http://ironphoenix.org/tril/gtklife/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ implementation of Conways Game of Life

DEPRECATED=	Uses obsolete glib12
EXPIRATION_DATE=	2018-12-20

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}" docdir="${DOCSDIR}"
INSTALLS_ICONS=	yes

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

OPTIONS_DEFINE=	GTK2 DOCS

GTK2_DESC=	GTK2 gui toolkit support (beta)
GTK2_USE=	GNOME=gtk20 XORG=x11
GTK2_USES=	pkgconfig
GTK2_USE_OFF=	GNOME=gtk12
GTK2_MAKE_ARGS=	gtk2=yes
GTK2_LDFLAGS=	-lX11
GTK2_VARS=	STARTUP_NOTIFY=true
GTK2_VARS_OFF=	STARTUP_NOTIFY=false

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtklife ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKSRC}/icon_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/gtklife.png
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
