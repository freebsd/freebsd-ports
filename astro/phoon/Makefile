# New ports collection makefile for:	phoon
# Date created:				14 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	phoon
PORTVERSION=	2003
CATEGORIES=	astro
MASTER_SITES=	http://www.acme.com/software/phoon/
PKGNAMESUFFIX=	_20jan
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}${PORTVERSION}

MAINTAINER=	xride@x12.dk
COMMENT=	Displays the phase of the moon

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes
MAN1=		phoon.1
PLIST_FILES=	bin/phoon

pre-patch:
	@${REINPLACE_CMD} -e 's|gmtoff = !!!;||g' \
		${WRKSRC}/date_parse.c

.include <bsd.port.mk>
