# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scite
PORTVERSION=	3.3.5
CATEGORIES=	editors gnome
MASTER_SITES=	SF/scintilla/SciTE/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Full-featured SCIntilla based text editor for GTK/GNOME

LIB_DEPENDS=	libscintilla.so:${PORTSDIR}/x11-toolkits/scintilla
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

OPTIONS_DEFINE=	DOCS FULL_BUFFER_MENU
FULL_BUFFER_MENU_DESC=	Show all files in buffer menu

WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

USES=		gmake pkgconfig
USE_GNOME=	gtk20
MAKEFILE=	makefile

MAN1=		scite.1
PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|[(]CC[)]|(CXX)|g ; s|[(]CCOMP[)]|(CC)|g ; \
		s| -Os||g' ${WRKSRC}/makefile
.if ${PORT_OPTIONS:MFULL_BUFFER_MENU}
	@${REINPLACE_CMD} -e 's|30, "/Buffers|props.GetInt("buffers") > 30 ? props.GetInt("buffers") - 10 : 30, "/Buffers|g' ${WRKSRC}/SciTEGTK.cxx
.endif
	@${REINPLACE_CMD} -e 's|netscape "file://$$(SciteDefaultHome)|xdg-open "file://${DOCSDIR}|' \
		${WRKSRC}/../src/SciTEGlobal.properties

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/SciTE ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../doc/scite.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/SciTE.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/Sci48M.png ${PREFIX}/share/pixmaps
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../src/*.properties ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.jpg ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.png ${DOCSDIR}
.endif

.include <bsd.port.mk>
