# New ports collection makefile for:	cal
# Version required:			3.4
# Date created:				6 July 1996
# Whom: Andrey Zakhvatov <andy@cgu.chel.su>
#
# $Id: Makefile,v 1.3 1996/11/17 09:05:25 obrien Exp $
#

DISTNAME=	cal-3.4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/shell

MAINTAINER=	andy@cgu.chel.su

WRKSRC=		${WRKDIR}/cal34/source
ALL_TARGET=	cal
MAN1=		cal.1

pre-patch:
	@ /bin/mv ${WRKSRC}/makefile.unx ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cal ${PREFIX}/bin/cal
	@${INSTALL_MAN} ${WRKSRC}/cal.1 ${PREFIX}/man/man1/cal.1
	@ if [ ! -d ${PREFIX}/etc/cal ]; then ${MKDIR} ${PREFIX}/etc/cal; chmod 0755 ${PREFIX}/etc/cal; fi
	@ if [ ! -f ${PREFIX}/etc/cal/calcol ]; then ${INSTALL_DATA} ${WRKDIR}/cal34/cal.col ${PREFIX}/etc/cal/calcol; fi
	@ if [ ! -f ${PREFIX}/etc/cal/caldat ]; then ${INSTALL_DATA} ${WRKDIR}/cal34/cal.dat ${PREFIX}/etc/cal/caldat; fi

.include <bsd.port.mk>
