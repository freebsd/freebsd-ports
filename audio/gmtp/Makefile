PORTNAME=	gmtp
PORTVERSION=	1.3.11
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/gMTP-${PORTVERSION}/

MAINTAINER=	freebsd-ports-local@be-well.ilk.org
COMMENT=	Media Transfer Protocol (MTP) GUI client
WWW=		http://gmtp.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmtp.so:multimedia/libmtp \
		libid3tag.so:audio/libid3tag \
		libFLAC.so:audio/flac \
		libvorbis.so:audio/libvorbis \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		dos2unix gmake gnome localbase pkgconfig
DOS2UNIX_FILES=	COPYING
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
GLIB_SCHEMAS=	org.gnome.gmtp.gschema.xml

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk3

# PR: 244712
# Workaround to fix linking with Clang >= 11 and GCC >= 10 which both set
# -fno-common by default. Upstream seems to have resolved this issue, so this
# line should be removed when updating to the next release.
CFLAGS+=	-fcommon

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
