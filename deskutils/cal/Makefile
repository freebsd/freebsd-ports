# Created by: Andrey Zakhvatov <andy@icc.surw.chel.su>
# $FreeBSD$

PORTNAME=	cal
PORTVERSION=	3.5
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SUNSITE/utils/shell

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced color version of standard calendar utility

LICENSE=	PD

WRKSRC=		${WRKDIR}/cal-3.5/source
MAKEFILE=	makefile.unx
ALL_TARGET=	cal

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/cal.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cal ${STAGEDIR}${PREFIX}/bin/cal
	${INSTALL_MAN}  ${WRKSRC}/cal.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/cal
	${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.col ${STAGEDIR}${ETCDIR}/calcol.sample
	${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.dat ${STAGEDIR}${ETCDIR}/caldat.sample

.include <bsd.port.mk>
