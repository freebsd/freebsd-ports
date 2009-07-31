# New ports collection makefile for:	urlgfe
# Date created:				8 January 2004
# Whom:					Nosov Artem <chip-set@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	urlgfe
PORTVERSION=	0.7.1
PORTREVISION?=	10
CATEGORIES=	ftp www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	urlget

MAINTAINER=	chip-set@mail.ru
COMMENT=	A download manager

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

USE_GNOME=	gtk20 lthack
WANT_GNOME=	yes
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomehier}!=""
WITH_GNOME=	yes
PLIST_SUB+=	GNOME:=""
.else
PLIST_SUB+=	GNOME:="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$||g'
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f
	@${REINPLACE_CMD} -e 's|[$$]{prefix}/doc/urlgfe|${DOCSDIR}|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|$$||g ; s|urlgfe_icon|urlgfe-icon|g ; \
		s|/usr/share/pixmaps/urlgfe/||g' ${WRKSRC}/${PORTNAME}.desktop
	@${REINPLACE_CMD} -e 's|	 -g|	 ${CFLAGS}|g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|@MKINSTALLDIRS@|$$(top_srcdir)/@MKINSTALLDIRS@|g ; \
		s|[$$][(]top_builddir[)]/[$$][(]MKINSTALLDIRS[)]|$$(top_srcdir)/mkinstalldirs|g' \
			${WRKSRC}/po/Makefile.in.in

.if defined(WITH_GNOME)
post-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/gnome/apps/Internet/
	@${INSTALL_DATA} ${WRKSRC}/pixmaps/${PORTNAME}-icon.png ${PREFIX}/share/pixmaps/
.endif

.include <bsd.port.post.mk>
