# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libopensync-plugin-evolution2
PORTVERSION=	0.22
PORTREVISION=	7
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	webmaster@kibab.com
COMMENT=	Evolution 2 plugin for the OpenSync framework

LIB_DEPENDS=	libopensync.so:${PORTSDIR}/devel/libopensync022

CONFLICTS=	libopensync-plugin-evolution2-devel-[0-9]*

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GNOME=	evolutiondataserver gconf2

NO_STAGE=	yes
.include <bsd.port.mk>
