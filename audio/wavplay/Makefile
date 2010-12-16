# New ports collection makefile for:	wavplay
# Date created:				14 January 2000
# Whom:					greg
#
# $FreeBSD$
#

PORTNAME=	wavplay
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A wav player and recorder

MAN1=		wavplay.1

PLIST_FILES=	bin/wavplay bin/wavrec

post-patch:
	@${REINPLACE_CMD} -e 's|u_long|u_int|g' ${WRKSRC}/*.c ${WRKSRC}/*.h

.include <bsd.port.mk>
