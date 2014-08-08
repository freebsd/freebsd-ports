# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scite
PORTVERSION=	3.4.4
CATEGORIES=	editors gnome
MASTER_SITES=	SF/scintilla/SciTE/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Full-featured SCIntilla based text editor for GTK/GNOME

LIB_DEPENDS=	libscintilla.so:${PORTSDIR}/x11-toolkits/scintilla
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

OPTIONS_DEFINE=	DOCS FULL_BUFFER_MENU
FULL_BUFFER_MENU_DESC=	Show all files in buffer menu

WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

USES=		desktop-file-utils gmake pkgconfig tar:tgz
USE_GNOME=	gtk20
MAKEFILE=	makefile

PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's| -Os||g' ${WRKSRC}/makefile
.if ${PORT_OPTIONS:MFULL_BUFFER_MENU}
	@${REINPLACE_CMD} -e 's|30, "/Buffers|props.GetInt("buffers") > 30 ? props.GetInt("buffers") - 10 : 30, "/Buffers|g' ${WRKSRC}/SciTEGTK.cxx
.endif
	@${REINPLACE_CMD} -e 's|netscape "file://$$(SciteDefaultHome)|xdg-open "file://${DOCSDIR}|' \
		${WRKSRC}/../src/SciTEGlobal.properties

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/SciTE ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../doc/scite.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/SciTE.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/Sci48M.png ${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../src/*.properties ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.jpg ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.png ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
