# New ports collection makefile for:	xmcd
# Version required:	2.0
# Date created:		16 Februar 1995
# Whom:			Gennady Sorokopud <gena@NetVision.net.il>
#
# $Id: Makefile,v 1.3 1995/04/11 19:46:58 asami Exp $
#

DISTNAME=	xmcd-2.0
CATEGORIES+=	audio
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/xmcd/ \
		ftp://crl.dec.com/pub/X11/contrib/applications/xmcd/

MAINTAINER=	deischen@iworks.InterWorks.org

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes
IS_INTERACTIVE=	yes	# asks a lot of questions

post-install:
	cp ${WRKSRC}/README ${PREFIX}/lib/X11/xmcd

.include <bsd.port.mk>
