# New ports collection makefile for:	ghfaxviewer
# Date created:			Fri Apr 20 13:08:00  MET DST 2001
# Whom:				Dominik Brettnacher <domi@saargate.de>
#
# $FreeBSD$
#

PORTNAME=	ghfaxviewer
PORTVERSION=	0.22.0
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	halifax

MAINTAINER=	domi@saargate.de

LIB_DEPENDS=	gnomeprint.13:${PORTSDIR}/print/gnomeprint \
		gconf-1.1:${PORTSDIR}/devel/gconf \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes

MAN1=	halifax.1 ghfaxviewer.1

.include <bsd.port.mk>
