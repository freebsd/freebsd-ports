# New ports collection makefile for:	plan
# Version required:			1.7.1
# Date created:				14 April 1996
# Whom:	Daniel Eischen <deischen@iworks.InterWorks.org>
#
# $Id: Makefile,v 1.10 1998/04/17 18:05:17 obrien Exp $
#

#	Also update	ports/japanese/plan/ (ja-plan) when this port is updated

DISTNAME=	plan-1.7.1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_XCONTRIB}  \
		ftp://ftp.fu-berlin.de/pub/unix/graphics/plan/
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	deischen@iworks.InterWorks.org

REQUIRES_MOTIF=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
ALL_TARGET=	freebsd
MAN1=		netplan.1 plan.1
MAN4=		plan.4

post-install:
	@${MKDIR} ${PREFIX}/share/netplan.dir

.include <bsd.port.mk>
