# New ports collection makefile for:	xmcd
# Version required:	2.3
# Date created:		16 Februar 1995
# Whom:			Gennady Sorokopud <gena@NetVision.net.il>
#
# $Id: Makefile,v 1.13 1998/08/31 03:27:26 hoek Exp $
#

DISTNAME=	xmcd-2.3
CATEGORIES=	audio
MASTER_SITES=	http://mercury.hypersurf.com/~amb/download/xmcd/src/

MAINTAINER=	deischen@iworks.InterWorks.org

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes

MAN1=		cddbcmd.1 wm2xmcd.1 xmcd.1 cda.1

post-install:
.for man in cddbcmd.1 wm2xmcd.1
	${GZIP_CMD} ${PREFIX}/man/man1/${man}
.endfor
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
