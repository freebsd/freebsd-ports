# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	grisbi
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/${PORTVERSION:R}.x/${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Personal accounting application

LICENSE=	GPLv2

LIB_DEPENDS=	libofx.so:finance/libofx		\
		libfreetype.so:print/freetype2		\
		libgoffice-0.10.so:devel/goffice	\
		libfontconfig.so:x11-fonts/fontconfig

USES=		tar:bzip2 desktop-file-utils gmake gnome iconv localbase	\
		pkgconfig shared-mime-info ssl

USE_GNOME=	cairo glib20 gtk30 intltool libgsf libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

GLIB_SCHEMAS=	org.gtk.grisbi.gschema.xml
INSTALLS_ICONS=	yes

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
