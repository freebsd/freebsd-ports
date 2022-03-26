PORTNAME=	gmtp
PORTVERSION=	1.3.11
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/gMTP-${PORTVERSION}/

MAINTAINER=	freebsd-ports-local@be-well.ilk.org
COMMENT=	Media Transfer Protocol (MTP) GUI client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmtp.so:multimedia/libmtp \
		libid3tag.so:audio/libid3tag \
		libFLAC.so:audio/flac \
		libvorbis.so:audio/libvorbis

USES=		dos2unix gmake gnome localbase pkgconfig
DOS2UNIX_FILES=	COPYING
USE_GNOME=	cairo gdkpixbuf2 glib20

GNU_CONFIGURE=	yes

# PR: 244712
# Workaround to fix linking with Clang >= 11 and GCC >= 10 which both set
# -fno-common by default. Upstream seems to have resolved this issue, so this
# line should be removed when updating to the next release.
CFLAGS+=	-fcommon

PORTDOCS=	AUTHORS ChangeLog README

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
