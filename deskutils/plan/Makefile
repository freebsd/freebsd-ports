# New ports collection makefile for:	plan
# Version required:			1.6
# Date created:				14 April 1996
# Whom:	Daniel Eischen <deischen@iworks.InterWorks.org>
#
# $Id: Makefile,v 1.6 1997/06/20 13:29:02 tg Exp $
#

DISTNAME=	plan-1.6.1
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
