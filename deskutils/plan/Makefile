# New ports collection makefile for:	plan
# Date created:				14 April 1996
# Whom:	Daniel Eischen <deischen@iworks.InterWorks.org>
#
# $FreeBSD$
#
# Also update	ports/japanese/plan/ (ja-plan) when this port is updated

PORTNAME=	plan
PORTVERSION=	1.8.2
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_XCONTRIB}  \
		ftp://ftp.fu-berlin.de/pub/unix/graphics/plan/
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	deischen@iworks.InterWorks.org

REQUIRES_MOTIF=	yes
WRKSRC=		${WRKDIR}/plan-1.8.2/src
ALL_TARGET=	freebsd
MAN1=		netplan.1 plan.1
MAN4=		plan.4

post-install:
	@${MKDIR} ${PREFIX}/share/netplan.dir

.include <bsd.port.mk>
