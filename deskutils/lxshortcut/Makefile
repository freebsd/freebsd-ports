# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lxshortcut
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/lxde/LXShortcut%20%28edit%20app%20shortcut%29/LXShortcut%20${PORTVERSION}/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Small utility used to edit easily application shortcuts

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USES=		gmake pkgconfig
USE_GNOME=	gtk20 intlhack
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS NLS

OPTIONS_SUB=	yes

NLS_USES=	gettext

SUB_FILES=	${PORTNAME}-start

DESKTOP_ENTRIES="LXShortcut" "" "${PORTNAME}" \
		"${PORTNAME}-start" "Settings;GTK;DesktopSettings;" true

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -i '' '/g_thread_init/,/gdk_threads_init/d' \
		${WRKSRC}/src/lxshortcut.c

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|src po|src|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-start ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
