# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	libopensync-plugin-file
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	File-Sync plugin for the opensync framework

LIB_DEPENDS=	libopensync.so:${PORTSDIR}/devel/libopensync022

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
USES=		pkgconfig tar:bzip2 libtool
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
