# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	grisbi
PORTVERSION=	1.0.2
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/${PORTVERSION:C|.$|x|}/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Personal accounting application

LICENSE=	GPLv2

LIB_DEPENDS=	libofx.so:finance/libofx	\
		libfreetype.so:print/freetype2	\
		libgoffice-0.8.so:devel/goffice	\
		libfontconfig.so:x11-fonts/fontconfig

USES=		tar:bzip2 desktop-file-utils gmake iconv localbase pkgconfig	\
		shared-mime-info ssl
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gtk20 glib20 intltool libxml2
INSTALLS_ICONS=	yes
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
