# Created by: ports@FreeBSD.org
# $FreeBSD$

PORTNAME=	libexif-gtk
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/libexif/${PORTNAME}/${PORTVERSION}

MAINTAINER=	marius@nuenneri.ch
COMMENT=	GTK+ widgets to display/edit EXIF tags

LICENSE=	LGPL21

LIB_DEPENDS=	libexif.so:graphics/libexif

USES=		libtool pathfix pkgconfig
USE_GNOME=	gtk20
USE_AUTOTOOLS=	autoconf
GUN_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's|-g ||g' ${WRKSRC}/configure.ac

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
