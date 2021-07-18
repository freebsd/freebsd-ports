# Created by: Michael Johnson <ahze@FreeBSD.org>

PORTNAME=	goocanvas
PORTVERSION=	2.0.4
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cairo-based canvas widget for GTK+ 3

LICENSE=	LGPL20

USES=		gmake gnome libtool pathfix pkgconfig python:build tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python=no
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR:H}|' \
		${WRKSRC}/configure

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|docs||g' ${WRKSRC}/Makefile.in

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|po||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
