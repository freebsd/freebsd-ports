# New ports collection makefile for:	plan
# Version required:			1.5.1
# Date created:				14 April 1996
# Whom:	Daniel Eischen <deischen@iworks.InterWorks.org>
#
# $Id: Makefile,v 1.1.1.1 1996/08/05 07:38:10 tg Exp $
#

DISTNAME=	plan-1.5.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/

MAINTAINER=	deischen@iworks.InterWorks.org

REQUIRES_MOTIF=	yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/plan.1
	gzip -9nf ${PREFIX}/man/man4/plan.4
.endif

.include <bsd.port.mk>
