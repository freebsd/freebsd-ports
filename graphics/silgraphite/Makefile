# New ports collection makefile for:	silgraphite
# Date created:				30 November 2008
# Whom:					Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	silgraphite
PORTVERSION=	2.3.1
CATEGORIES=	graphics devel
MASTER_SITES=	SF

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Font engine for complex non-Roman writing systems

OPTIONS=	FREETYPE "Build with Freetype support" on

USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	"-I${LOCALBASE}/include" "-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-xft --without-pangographite

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FREETYPE)
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

.include <bsd.port.post.mk>
