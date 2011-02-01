# New ports collection makefile for:	xournal
# Date created:		21 Jan 2011
# Whom:			Jan Henrik Sylvester <me@janh.de>
#
# $FreeBSD$
#

PORTNAME=	xournal
PORTVERSION=	0.4.5
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	me@janh.de
COMMENT=	A notetaking application that can annotate PDFs

LIB_DEPENDS=	poppler-glib.5:${PORTSDIR}/graphics/poppler-gtk

LICENSE=	GPLv2

MAKE_JOBS_SAFE=	yes
USE_GNOME=	desktopfileutils libgnomecanvas
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install desktop-install

OPTIONS=	GHOSTSCRIPT "Install ghostscript (PS/PDF as bitmap bg)" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GHOSTSCRIPT)
USE_GHOSTSCRIPT_RUN=	yes
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|$$(DESTDIR)/usr/share/|$$(DESTDIR)$$$$desktopdir/|g' \
		-e 's|/usr/local/share|"$$(datadir)"|' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} && ${MAKE} install-doc-local)
.endif

.include <bsd.port.post.mk>
