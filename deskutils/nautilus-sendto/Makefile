# New ports collection makefile for:	nautilus-sendto
# Date created:		2004-12-03
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nautilus-sendto
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/nautilus-sendto/0.3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integration between nautilus, evolution, and gaim

BUILD_DEPENDS=	gaim:${PORTSDIR}/net/gaim \
		evolution:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_GNOME=	intlhack gnomeprefix gnometarget nautilus2 gnomehack

.include <bsd.port.mk>
