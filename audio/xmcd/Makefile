# New ports collection makefile for:	xmcd
# Version required:	2.1
# Date created:		16 Februar 1995
# Whom:			Gennady Sorokopud <gena@NetVision.net.il>
#
# $Id: Makefile,v 1.6 1996/11/18 09:52:29 asami Exp $
#

DISTNAME=	xmcd-2.1
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
