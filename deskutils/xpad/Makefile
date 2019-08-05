# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpad
PORTVERSION=	5.0.0
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual note-pad system for your X11 desktop

LICENSE=	GPLv3

RUN_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

CONFLICTS_INSTALL=	xpad3-[0-9]*
USES=		autoreconf compiler:c++11-lang gmake pkgconfig tar:bzip2
USE_XORG=	x11 sm ice
USE_GNOME=	gtk30 intltool gtksourceview3 cairo
INSTALLS_ICONS=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
PORTDOCS=	*

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|glib/glist.h|glib.h|g' \
		${WRKSRC}/src/xpad-undo.c
	@${REINPLACE_CMD} -e 's|/etc/xdg/autostart|${LOCALBASE}/etc/xdg/autostart|g' \
		${WRKSRC}/Makefile.am

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO THANKS
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
