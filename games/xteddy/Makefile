# New ports collection makefile for:   xteddy
# Version required:    1.0
# Date created:        3 June 1998
# Whom:                Eckart "Isegrim" Hofmann
#
# $FreeBSD$
#

DISTNAME=	xteddy-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.leo.org:/pub/comp/usenet/comp.sources.x/xteddy/

MAINTAINER=	Isegrim@Wunder-Nett.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

NO_CDROM=	"Can only be distributed for free"

USE_IMAKE=	yes
MAN1=		xteddy.1

post-install:
		strip ${PREFIX}/bin/xteddy
.include <bsd.port.mk>
