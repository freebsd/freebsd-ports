# Created by: Andrey Zakhvatov <andy@icc.surw.chel.su>
# $FreeBSD$

PORTNAME=		cal
PORTVERSION=		3.5
PORTREVISION=		1
CATEGORIES=		deskutils
MASTER_SITES=		SUNSITE/utils/shell

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced color version of standard calendar utility

WRKSRC=		${WRKDIR}/cal-3.5/source
MAKEFILE=	makefile.unx
ALL_TARGET=	cal

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cal ${STAGEDIR}${PREFIX}/bin/cal
	${MV} ${WRKSRC}/cal.1 ${WRKSRC}/cal.1.orig
	${SED} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/cal.1.orig > ${WRKSRC}/cal.1
	${INSTALL_MAN}  ${WRKSRC}/cal.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/cal
	@${CHMOD} 0755  ${STAGEDIR}${PREFIX}/etc/cal
	${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.col ${STAGEDIR}${ETCDIR}/calcol.sample
	${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.dat ${STAGEDIR}${ETCDIR}/caldat.sample

.include <bsd.port.mk>
