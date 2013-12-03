# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/goocanvas2/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	goocanvas
PORTVERSION=	2.0.2
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Canvas widget for GTK+ 3

USES=		gmake pathfix pkgconfig
USE_GNOME=	gtk30 introspection:build ltverhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_XZ=		yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/gtk-doc/html/goocanvas2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|docs||g' ${WRKSRC}/Makefile.in
.endif
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|po||g' ${WRKSRC}/Makefile.in
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgoocanvas-2.0.so.9

.include <bsd.port.mk>
