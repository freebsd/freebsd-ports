# New ports collection makefile for:	plan
# Version required:			1.7.1
# Date created:				14 April 1996
# Whom:	Daniel Eischen <deischen@iworks.InterWorks.org>
#
# $Id: Makefile,v 1.8 1998/03/22 18:01:28 obrien Exp $
#

#	Also update	ports/japanese/plan/ (ja-plan) when this port is updated

DISTNAME=	plan-1.7.1
CATEGORIES=	misc
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
