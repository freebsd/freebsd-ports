# New ports collection makefile for:	xmcd
# Version required:	2.0
# Date created:		16 Februar 1995
# Whom:			Gennady Sorokopud <gena@NetVision.net.il>
#
# $Id: Makefile,v 1.5 1996/11/15 23:14:50 obrien Exp $
#

DISTNAME=	xmcd-2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/xmcd

MAINTAINER=	deischen@iworks.InterWorks.org

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes
IS_INTERACTIVE=	yes	# asks a lot of questions

post-install:
	${CP} ${WRKSRC}/README ${PREFIX}/lib/X11/xmcd

.include <bsd.port.mk>
