# $FreeBSD$

PORTNAME=	tagutil
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://files.kaworu.ch/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to manage tags in music files

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib

USES=		pkgconfig
MAKE_ENV=	DESTDIR="${PREFIX}"

MAN1=		tagutil.1
PLIST_FILES=	bin/tagutil

MANCOMPRESSED=	yes

.include <bsd.port.mk>
