# New ports collection makefile for:   cdplay
# Date created:        8 July 1997
# Whom:                Antti Kaipila <anttik@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	cdplay
PORTVERSION=	0.92
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dannyboy

MAINTAINER=	anttik@iki.fi
COMMENT=	CD-player with text-based user interface

MAN1=		cdplay.1
PLIST_FILES=	bin/cdplay

pre-patch:
	@${GUNZIP_CMD} ${WRKSRC}/cdplay.1.gz

.include <bsd.port.mk>
