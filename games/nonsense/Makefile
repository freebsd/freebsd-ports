PORTNAME=	nonsense
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nonsense text generator

USES=		shebangfix
SHEBANG_FILES=	nonsense
NO_BUILD=	yes
NO_ARCH=	yes

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
