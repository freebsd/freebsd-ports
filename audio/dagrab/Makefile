# New ports collection makefile for: dagrab
# Version required:	0.3.2
# Date created:		2nd, Jan 1999
# Whom:			Chia-liang Kao <clkao@CirX.ORG>
#
# $FreeBSD$
#

DISTNAME=	dagrab-0.3.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/cdrom

PATCH_SITES=	http://www.freebsd.org/~cpiazza/distfiles/
PATCHFILES=	dagrab-0.3.3-freebsd.patch.gz

MAINTAINER=	clkao@CirX.ORG

MAN1=		dagrab.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dagrab ${PREFIX}/bin/dagrab
	@${INSTALL_MAN} ${WRKSRC}/dagrab.1 ${MANPREFIX}/man/man1/dagrab.1

.include <bsd.port.mk>
