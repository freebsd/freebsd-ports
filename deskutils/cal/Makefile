# New ports collection makefile for:	cal
# Date created:				2 April 1997
# Whom:	Andrey Zakhvatov <andy@icc.surw.chel.su>
#
# $FreeBSD$
#

PORTNAME=		cal
PORTVERSION=		3.5
CATEGORIES=		deskutils
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/shell

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Enhanced color version of standard calendar utility

WRKSRC=		${WRKDIR}/cal-3.5/source
MAKEFILE=	makefile.unx
ALL_TARGET=	cal
MAN1=		cal.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cal ${PREFIX}/bin/cal
	${MV} ${WRKSRC}/cal.1 ${WRKSRC}/cal.1.orig
	${SED} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/cal.1.orig > ${WRKSRC}/cal.1
	${INSTALL_MAN}  ${WRKSRC}/cal.1 ${PREFIX}/man/man1/cal.1
	@${MKDIR} ${PREFIX}/etc/cal
	@${CHMOD} 0755  ${PREFIX}/etc/cal
	if [ ! -f ${PREFIX}/etc/cal/calcol ]; then ${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.col ${PREFIX}/etc/cal/calcol; fi
	if [ ! -f ${PREFIX}/etc/cal/caldat ]; then ${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.dat ${PREFIX}/etc/cal/caldat; fi

.include <bsd.port.mk>
