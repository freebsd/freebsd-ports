# New ports collection makefile for:	xmcd
# Version required:	2.3
# Date created:		16 Februar 1995
# Whom:			Gennady Sorokopud <gena@NetVision.net.il>
#
# $Id: Makefile,v 1.14 1998/08/31 06:56:58 asami Exp $
#

DISTNAME=	xmcd-2.4
CATEGORIES=	audio
MASTER_SITES=	http://mercury.hypersurf.com/~amb/download/xmcd/src/

MAINTAINER=	eischen@vigrid.com

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes

MAN1=		cddbcmd.1 wm2xmcd.1 xmcd.1 cda.1

post-install:
.for man in cddbcmd.1 wm2xmcd.1 xmcd.1 cda.1
	${GZIP_CMD} ${PREFIX}/man/man1/${man}
.endfor
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
