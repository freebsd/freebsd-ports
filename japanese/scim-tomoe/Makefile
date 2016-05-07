# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scim-tomoe
PORTVERSION=	0.6.0
PORTREVISION=	12
CATEGORIES=	japanese
MASTER_SITES=	SF/tomoe/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM IMEngine module using Tomoe

BUILD_DEPENDS=	scim:textproc/scim
LIB_DEPENDS=	libtomoe.so:japanese/tomoe \
		libtomoe-gtk.so:japanese/libtomoe-gtk

USE_GNOME=	intlhack
USES=		gettext gmake iconv libtool:keepla pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/scim-tomoe \
		lib/scim-1.0/1.4.0/Helper/tomoe.a \
		lib/scim-1.0/1.4.0/Helper/tomoe.la \
		lib/scim-1.0/1.4.0/Helper/tomoe.so \
		share/locale/ja/LC_MESSAGES/scim-tomoe.mo \
		share/scim/icons/scim-tomoe.png

.include <bsd.port.mk>
