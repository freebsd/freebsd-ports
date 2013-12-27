# Created by: Jan Henrik Sylvester <me@janh.de>
# $FreeBSD$

PORTNAME=	xournal
PORTVERSION=	0.4.7
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	me@janh.de
COMMENT=	Notetaking application that can annotate PDFs

LICENSE=	GPLv2

LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib

USES=		pkgconfig desktop-file-utils shared-mime-info
USE_GNOME=	libgnomecanvas
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install desktop-install

OPTIONS_DEFINE=		GHOSTSCRIPT
GHOSTSCRIPT_DESC=	Install ghostscript (PS/PDF as bitmap bg)
OPTIONS_DEFAULT=	GHOSTSCRIPT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGHOSTSCRIPT}
USE_GHOSTSCRIPT_RUN=	yes
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|$$(DESTDIR)/usr/share/|$$(DESTDIR)$$$$desktopdir/|g' \
		-e 's|/usr/local/share|"$$(datadir)"|' \
		-e 's|ln -s $$(DESTDIR)$$(pkgdatadir)/pixmaps|ln -s $$(pkgdatadir)/pixmaps|' \
		${WRKSRC}/Makefile.in

post-install:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} install-doc-local)

.include <bsd.port.mk>
