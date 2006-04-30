# New ports collection makefile for:	nautilus-sendto
# Date created:		2004-12-03
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/deskutils/nautilus-sendto/Makefile,v 1.2 2006/02/24 05:52:41 marcus Exp $

PORTNAME=	nautilus-sendto
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/nautilus-sendto/0.5

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integration between nautilus, evolution, and gaim

BUILD_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim \
		evolution:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim \
		evolution:${PORTSDIR}/mail/evolution

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	intlhack gnomeprefix gnometarget nautilus2 gnomehack

.include <bsd.port.mk>
