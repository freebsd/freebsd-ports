# New ports collection makefile for:	tagutil
# Date created:		2009-03-27
# Whom:			bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tagutil
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://files.kaworu.ch/

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	A tool to manage tags in music files

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib

USE_GNOME=	pkgconfig
MAKE_JOBS_SAFE=	yes
MAKE_ENV=	DESTDIR="${PREFIX}"

MAN1=		tagutil.1
PLIST_FILES=	bin/tagutil

MANCOMPRESSED=	yes

.include <bsd.port.mk>
