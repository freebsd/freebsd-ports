# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	silgraphite
PORTVERSION=	2.3.1
CATEGORIES=	graphics devel
MASTER_SITES=	SF

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Font engine for complex non-Roman writing systems

OPTIONS_DEFINE=	FREETYPE
OPTIONS_DEFAULT=	FREETYPE

USE_PKGCONFIG=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-xft --without-pangographite

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
USE_ICONV=	yes
CONFIGURE_ARGS+=	--with-freetype
PLIST_SUB+=	WITH_FREETYPE=""
.else
CONFIGURE_ARGS+=	--without-freetype
PLIST_SUB+=	WITH_FREETYPE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/engine/Makefile.in

.include <bsd.port.mk>
