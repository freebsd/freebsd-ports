# Created by: Andrey Zakhvatov <andy@icc.surw.chel.su>
# $FreeBSD$

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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cal ${STAGEDIR}${PREFIX}/bin/cal
	${MV} ${WRKSRC}/cal.1 ${WRKSRC}/cal.1.orig
	${SED} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/cal.1.orig > ${WRKSRC}/cal.1
	${INSTALL_MAN}  ${WRKSRC}/cal.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/cal
	@${CHMOD} 0755  ${STAGEDIR}${PREFIX}/etc/cal
.if !exists(${STAGEDIR}${ETCDIR}/calcol)
	${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.col ${STAGEDIR}${ETCDIR}/calcol
.endif
.if !exists(${STAGEDIR}${ETCDIR}/caldat)
	${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.dat ${STAGEDIR}${ETCDIR}/caldat
.endif

.include <bsd.port.mk>
