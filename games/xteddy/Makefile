# New ports collection makefile for:   xteddy
# Date created:        3 June 1998
# Whom:                Eckart "Isegrim" Hofmann
#
# $FreeBSD$
#

PORTNAME=	xteddy
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/usenet/comp.sources.x/xteddy/

MAINTAINER=	Isegrim@Wunder-Nett.org
COMMENT=	A cuddlesome teddy for the X desktop

NO_CDROM=	"Can only be distributed for free"

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		xteddy.1
PLIST_FILES=	bin/xteddy

post-install:
		${STRIP_CMD} ${PREFIX}/bin/xteddy
.include <bsd.port.mk>
