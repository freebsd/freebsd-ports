# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmpc-wikipedia
PORTVERSION=	11.8.16
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wikipedia info for gmpc

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpd.so:${PORTSDIR}/audio/libmpd \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_GNOME=	intltool glib20 gtk20
USES=		gettext gmake libtool pkgconfig
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
