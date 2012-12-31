# $FreeBSD$

PORTNAME=	tagutil
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://files.kaworu.ch/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	A tool to manage tags in music files

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib

USE_PKGCONFIG=	build
MAKE_JOBS_SAFE=	yes
MAKE_ENV=	DESTDIR="${PREFIX}"

MAN1=		tagutil.1
PLIST_FILES=	bin/tagutil

MANCOMPRESSED=	yes

.include <bsd.port.mk>
