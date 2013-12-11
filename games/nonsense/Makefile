# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	nonsense
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Nonsense text generator

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.options.mk>

post-configure:
		${REINPLACE_CMD} -e "s,/usr/local,${PREFIX}," ${WRKSRC}/nonsense
		${SED} -e "s^%%PREFIX%%^${PREFIX}^g" \
			< ${FILESDIR}/nonsense.6 > ${WRKSRC}/nonsense.6

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/nonsense ${STAGEDIR}${PREFIX}/bin
		${MKDIR} ${STAGEDIR}${DATADIR}/data
		${MKDIR} ${STAGEDIR}${DATADIR}/template
		${INSTALL_DATA} ${WRKSRC}/*.data ${STAGEDIR}${DATADIR}/data
		${INSTALL_DATA} ${WRKSRC}/*.template ${STAGEDIR}${DATADIR}/template
		${INSTALL_MAN} ${WRKSRC}/nonsense.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/

.include <bsd.port.mk>
