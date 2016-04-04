# Created by: Nosov Artem <chip-set@mail.ru>
# $FreeBSD$

PORTNAME=	urlgfe
PORTVERSION=	0.7.1
PORTREVISION=	16
CATEGORIES=	ftp www
MASTER_SITES=	SF/urlget/Urlgfe%20%28legacy%29/${PORTVERSION}

MAINTAINER=	chip-set@mail.ru
COMMENT=	Download manager

LIB_DEPENDS=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
USES=		dos2unix libtool pkgconfig
USE_GNOME=	gtk20
USE_OPENSSL=	yes

OPTIONS_DEFINE=	DOCS NLS
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f
	@${REINPLACE_CMD} -e 's|[$$]{prefix}/doc/urlgfe|${DOCSDIR}|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} \
		's|/usr/share/pixmaps/urlgfe/urlgfe_icon|${PREFIX}/share/pixmaps/urlgfe-icon|' \
		${WRKSRC}/${PORTNAME}.desktop
	@${REINPLACE_CMD} -e 's|	 -g|	 ${CFLAGS}|g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|@MKINSTALLDIRS@|$$(top_srcdir)/@MKINSTALLDIRS@|g ; \
		s|[$$][(]top_builddir[)]/[$$][(]MKINSTALLDIRS[)]|$$(top_srcdir)/mkinstalldirs|g' \
			${WRKSRC}/po/Makefile.in.in

post-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	@${INSTALL_DATA} ${WRKSRC}/pixmaps/${PORTNAME}-icon.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
