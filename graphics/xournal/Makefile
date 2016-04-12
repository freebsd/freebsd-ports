# Created by: Jan Henrik Sylvester <me@janh.de>
# $FreeBSD$

PORTNAME=	xournal
PORTVERSION=	0.4.8
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	me@janh.de
COMMENT=	Notetaking application that can annotate PDFs

LICENSE=	GPLv2

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib

USES=		pkgconfig desktop-file-utils shared-mime-info
USE_GNOME=	libgnomecanvas
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install desktop-install

OPTIONS_DEFINE=		GHOSTSCRIPT DOCS
GHOSTSCRIPT_DESC=	Install ghostscript (PS/PDF as bitmap bg)
OPTIONS_DEFAULT=	GHOSTSCRIPT

GHOSTSCRIPT_USES=	ghostscript:run

PORTDOCS_MAIN=	AUTHORS \
		ChangeLog \
		COPYING \
		README
PORTDOCS=	${PORTDOCS_MAIN} \
		html-doc/screenshot.png \
		html-doc/manual.html \
		html-doc/pixmaps/lightgreen.png \
		html-doc/pixmaps/medium.png \
		html-doc/pixmaps/ruler.png \
		html-doc/pixmaps/green.png \
		html-doc/pixmaps/magenta.png \
		html-doc/pixmaps/default-pen.png \
		html-doc/pixmaps/lasso.png \
		html-doc/pixmaps/highlighter.png \
		html-doc/pixmaps/red.png \
		html-doc/pixmaps/hand.png \
		html-doc/pixmaps/fullscreen.png \
		html-doc/pixmaps/white.png \
		html-doc/pixmaps/xoj.svg \
		html-doc/pixmaps/pencil.png \
		html-doc/pixmaps/rect-select.png \
		html-doc/pixmaps/stretch.png \
		html-doc/pixmaps/blue.png \
		html-doc/pixmaps/lightblue.png \
		html-doc/pixmaps/orange.png \
		html-doc/pixmaps/yellow.png \
		html-doc/pixmaps/gray.png \
		html-doc/pixmaps/xournal.svg \
		html-doc/pixmaps/xournal.png \
		html-doc/pixmaps/thin.png \
		html-doc/pixmaps/thick.png \
		html-doc/pixmaps/eraser.png \
		html-doc/pixmaps/recycled.png \
		html-doc/pixmaps/shapes.png \
		html-doc/pixmaps/black.png \
		html-doc/pixmaps/text-tool.png

post-patch:
	@${REINPLACE_CMD} \
		-e 's|$$(DESTDIR)/usr/share/|$$(DESTDIR)$$$$desktopdir/|g' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS_MAIN:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html-doc
	(cd ${WRKSRC} && ${COPYTREE_SHARE} html-doc/ ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
