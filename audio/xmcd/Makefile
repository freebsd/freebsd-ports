# New ports collection makefile for:	xmcd
# Version required:	2.3
# Date created:		16 Februar 1995
# Whom:			Gennady Sorokopud <gena@NetVision.net.il>
#
# $Id: Makefile,v 1.11 1998/08/25 00:43:44 asami Exp $
#

DISTNAME=	xmcd-2.3
CATEGORIES=	audio
MASTER_SITES=	http://mercury.hypersurf.com/~amb/download/xmcd/src/

MAINTAINER=	deischen@iworks.InterWorks.org

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes

MAN1=		cddbcmd.1 wm2xmcd.1 xmcd.1 cda.1
MANCOMPRESSED=	no

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
