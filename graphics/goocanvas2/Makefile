# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/goocanvas2/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	goocanvas
PORTVERSION=	2.0.1
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Canvas widget for GTK+ 3

LATEST_LINK=	goocanvas2

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USES=		pathfix pkgconfig
USE_GNOME=	gtk30 ltverhack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_XZ=		yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/gtk-doc/html/goocanvas2

NO_STAGE=	yes
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

.include <bsd.port.mk>
