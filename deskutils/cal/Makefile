# New ports collection makefile for:	cal
# Version required:			3.5
# Date created:				2 April 1997
# Whom:	Andrey Zakhvatov <andy@icc.surw.chel.su>
#
# $Id: Makefile,v 1.5 1997/05/12 06:33:23 max Exp $
#

DISTNAME=		cal-3.5
CATEGORIES=		deskutils
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/shell

MAINTAINER=	andy@icc.surw.chel.su

WRKSRC=		${WRKDIR}/cal-3.5/source
MAKEFILE=	makefile.unx
ALL_TARGET=	cal
MAN1=		cal.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cal ${PREFIX}/bin/cal
	${INSTALL_MAN}  ${WRKSRC}/cal.1 ${PREFIX}/man/man1/cal.1
	@${MKDIR} ${PREFIX}/etc/cal
	@chmod 0755  ${PREFIX}/etc/cal
	if [ ! -f ${PREFIX}/etc/cal/calcol ]; then ${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.col ${PREFIX}/etc/cal/calcol; fi
	if [ ! -f ${PREFIX}/etc/cal/caldat ]; then ${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.dat ${PREFIX}/etc/cal/caldat; fi

.include <bsd.port.mk>
