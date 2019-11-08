# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkatlantic
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/gtkatlantic/downloads/v${PORTVERSION:R}/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Game like Monopoly(tm)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome localbase:ldflags pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

PORTDOCS=	AUTHORS ChangeLog NEWS README

DESKTOP_ENTRIES="GtkAtlantic" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;BoardGame;" ""

OPTIONS_DEFINE=	DOCS

# Wrong versioning upstream, Upstream use GTK3 in newer Versions
PORTSCOUT=	ignore:1

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS=/s|-ggdb|$$CFLAGS|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|mkdir |$$(mkdir_p) |g' ${WRKSRC}/Makefile.in

post-install:
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ../../share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
