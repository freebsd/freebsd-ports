# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kasumi
PORTVERSION=	2.5
PORTREVISION=	8
CATEGORIES=	japanese
MASTER_SITES=	OSDN/${PORTNAME}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Dictionary management tool for anthy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libanthy.so:japanese/anthy \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang gmake gnome iconv:wchar_t localbase:ldflags pkgconfig
USE_GNOME=	gtk20 cairo gdkpixbuf2

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
