# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uim-tomoe-gtk
PORTVERSION=	0.6.0
PORTREVISION=	11
CATEGORIES=	japanese
MASTER_SITES=	SF/tomoe/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	UIM helper program for Tomoe

LIB_DEPENDS=	libtomoe.so:${PORTSDIR}/japanese/tomoe \
		libtomoe-gtk.so:${PORTSDIR}/japanese/libtomoe-gtk \
		libuim.so:${PORTSDIR}/textproc/uim

USE_GNOME=	lthack gtk20
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/uim-tomoe-gtk \
		share/locale/ja/LC_MESSAGES/uim-tomoe-gtk.mo

CONFIGURE_ENV+=	GMSGFMT="${LOCALBASE}/bin/msgfmt"

.include <bsd.port.mk>
