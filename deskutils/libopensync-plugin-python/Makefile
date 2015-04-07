# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libopensync-plugin-python
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	webmaster@kibab.com
COMMENT=	Python plugin for the OpenSync framework

BROKEN=		Unfetchable
DEPRECATED=	Unfetchable, devices are not produced anymore
EXPIRATION_DATE=	2015-05-07

LIB_DEPENDS=	libopensync.so:${PORTSDIR}/devel/libopensync022

CONFLICTS=	libopensync-plugin-python-devel-[0-9]*

USES=		libtool pkgconfig python tar:bzip2
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
