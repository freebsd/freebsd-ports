PORTNAME=	gftp
PORTVERSION=	2.9.1b
PORTREVISION=	1
CATEGORIES=	ftp

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Free multithreaded GTK-based FTP and SFTP client
WWW=		http://gftp.seul.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		autoreconf desktop-file-utils gettext-tools gnome gmake pathfix \
		pkgconfig ssl tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	masneyb
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CFLAGS+=	-D_WANT_SEMUN

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext iconv
NLS_CONFIGURE_OFF=	--disable-nls
NLS_CONFIGURE_ENABLE=	nls
NLS_CPPFLAGS=		-I${LOCALBASE}/include
NLS_LIBS=		-L${LOCALBASE}/lib -lintl

post-patch:
	@${MKDIR} ${WRKSRC}/autoconf
	@${MKDIR} ${WRKSRC}/autoconf-m4
	@${TOUCH} ${WRKSRC}/autoconf/config.rpath

.include <bsd.port.mk>
