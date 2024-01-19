PORTNAME=	rgbpaint
PORTVERSION=	0.8.7
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	SF/mtpaint/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very basic painting program
WWW=		https://mtpaint.sourceforge.net/rgbpaint.html

LICENSE=	GPLv2+

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		gettext gnome pkgconfig tar:bzip2 xorg
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_XORG=	x11
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${PREFIX}/share/man/man1 \
		--locale=${PREFIX}/share/locale cflags slow intl man
CFLAGS+=	-fcommon

DESKTOP_ENTRIES="rgbPaint" "" "" "${PORTNAME}" "" true

post-patch:
	@${REINPLACE_CMD} '/if \[/s|==|=|g ; \
		 /gcc/s|^|#| ; \
		 /GTK_LIB/s| -s||' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's|$$(MT_MAN_DEST)|$$(DESTDIR)&|g' \
		${WRKSRC}/doc/Makefile
	@${REINPLACE_CMD} 's|$$(MT_LANG_DEST)|$$(DESTDIR)&|g' \
		${WRKSRC}/po/Makefile
	@${REINPLACE_CMD} 's|$$(BIN_INSTALL)|$$(DESTDIR)&|g ; \
		 /^LDFLAGS/s|$$| -lX11 -lm -lintl|' \
		${WRKSRC}/src/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rgbpaint

.include <bsd.port.mk>
