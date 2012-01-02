# New ports collection makefile for:	ed
# Date created:		Mon  2 Jan 2012 11:27:01 CET
# Whom:			Johan van Selst <johans@sack.nl>
#
# $FreeBSD$

PORTNAME=	ed
PORTVERSION=	1.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The GNU version of the ed editor

INFO=		ged

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

PLIST_FILES=	bin/ged bin/gred
MAN1=		ged.1
MLINKS=		ged.1 gred.1

.include <bsd.port.mk>
