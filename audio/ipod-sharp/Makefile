# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	ipod-sharp
PORTVERSION=	0.8.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.banshee.fm/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Manipulate iTunesDB used in Apple iPod devices

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/podsleuth.pc:${PORTSDIR}/misc/podsleuth \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/podsleuth.pc:${PORTSDIR}/misc/podsleuth \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gmake pathfix
USE_GNOME=	gtksharp20

.include <bsd.port.mk>
