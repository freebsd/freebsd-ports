# New ports collection makefile for:	ascd
# Version required:		0.12.1
# Date created:			29 November 1998
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.8 1999/04/22 12:28:33 jseger Exp $
#

DISTNAME=	ascd-0.12.1+lib-src
PKGNAME=	ascd-0.12.1
CATEGORIES=	audio afterstep windowmaker
MASTER_SITES=	http://worldserver.oleane.com/rsn/Archives/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	default

MAN1=		ascd.1

.include <bsd.port.mk>
