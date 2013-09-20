# Created by: Jeff Molofee
# $FreeBSD$

PORTNAME=	timeless
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	shaun

MAINTAINER=	nehe@cruzinternet.com
COMMENT=	FreeBSD/SDL port of Tran's Timeless Demo with Sound

USE_SDL=	sdl mixer

PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/time.s3m
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
.include <bsd.port.mk>
