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

NO_CDROM=	"Can only be distributed for free"

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		xteddy.1

post-install:
		strip ${PREFIX}/bin/xteddy
.include <bsd.port.mk>
