# Created by: Jan Henrik Sylvester <me@janh.de>
# $FreeBSD$

PORTNAME=	xournal
PORTVERSION=	0.4.7
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	me@janh.de
COMMENT=	A notetaking application that can annotate PDFs

LICENSE=	GPLv2

LIB_DEPENDS=	poppler-glib:${PORTSDIR}/graphics/poppler-glib

MAKE_JOBS_SAFE=	yes
USE_GNOME=	desktopfileutils libgnomecanvas
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
		${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC} && ${MAKE} install-doc-local)
.endif

.include <bsd.port.mk>
