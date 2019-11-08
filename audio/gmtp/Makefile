# $FreeBSD$

PORTNAME=	gmtp
PORTVERSION=	1.3.10
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/gMTP-${PORTVERSION}/

MAINTAINER=	freebsd-ports-local@be-well.ilk.org
COMMENT=	Media Transfer Protocol (MTP) GUI client

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libmtp.so:multimedia/libmtp \
		libid3tag.so:audio/libid3tag \
		libFLAC.so:audio/flac \
		libvorbis.so:audio/libvorbis

GNU_CONFIGURE=	yes
USES=		gmake gnome localbase pkgconfig
USE_GNOME=	cairo gdkpixbuf2 glib20

PORTDOCS=	AUTHORS COPYING ChangeLog README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_RADIO=	GTK
OPTIONS_RADIO_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2
OPTIONS_SUB=		yes

GTK3_USE=		GNOME=gtk30
GTK3_CONFIGURE_WITH=	gtk3
GTK3_VARS=		GLIB_SCHEMAS=org.gnome.gmtp.gschema.xml
GTK2_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libfontconfig.so:x11-fonts/fontconfig
GTK2_USE=		GNOME=gtk20,gconf2
GTK2_CONFIGURE_WITH=	gtk2
GTK2_VARS=		GCONF_SCHEMAS=gmtp.schemas
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
