PORTNAME=	grisbi
PORTVERSION=	3.0.4
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/${PORTVERSION:R}.x/${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Personal accounting application
WWW=		https://www.grisbi.org/

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>0:textproc/p5-XML-Parser
LIB_DEPENDS=	libofx.so:finance/libofx		\
		libharfbuzz.so:print/harfbuzz		\
		libfreetype.so:print/freetype2		\
		libgoffice-0.10.so:devel/goffice	\
		libfontconfig.so:x11-fonts/fontconfig

USES=		desktop-file-utils gmake gnome iconv localbase	\
		pkgconfig shared-mime-info ssl tar:bzip2

USE_GNOME=	cairo gdkpixbuf glib20 gtk30 intltool libgsf libxml2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
