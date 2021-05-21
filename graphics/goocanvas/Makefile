# Created by: Michael Johnson <ahze@FreeBSD.org>

PORTNAME=	goocanvas
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Cairo-based canvas widget for GTK+

LICENSE=	LGPL20

PORTSCOUT=	ignore:1

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gnome libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 gtk20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
LIBS=		-lm

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext localbase

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR:H}|' \
		${WRKSRC}/configure

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|docs||g' ${WRKSRC}/Makefile.in

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|po||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
