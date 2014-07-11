# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libopensync-plugin-evolution2
PORTVERSION=	0.22
PORTREVISION=	9
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Evolution 2 plugin for the OpenSync framework

LIB_DEPENDS=	libopensync.so:${PORTSDIR}/devel/libopensync022

CONFLICTS=	libopensync-plugin-evolution2-devel-[0-9]*

GNU_CONFIGURE=	yes
USES=		pkgconfig tar:bzip2 libtool
USE_GNOME=	evolutiondataserver gconf2
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
