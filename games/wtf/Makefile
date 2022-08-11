PORTNAME=	wtf
PORTVERSION=	20220320
CATEGORIES=	games
MASTER_SITES=	SF/bsdwtf

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Translates common Internet acronyms

LICENSE=	PD

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=		OFFENSIVE
OPTIONS_DEFAULT=	OFFENSIVE
OFFENSIVE_DESC=		Include offensive acronyms

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/misc|${DATADIR}|g' ${WRKSRC}/wtf*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wtf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wtf.6 ${STAGEDIR}${MAN6PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/acronyms ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/acronyms.comp ${STAGEDIR}${DATADIR}

do-install-OFFENSIVE-on:
	${INSTALL_DATA} ${WRKSRC}/acronyms-o.real ${STAGEDIR}${DATADIR}/acronyms-o

do-install-OFFENSIVE-off:
	${INSTALL_DATA} ${WRKSRC}/acronyms-o.fake ${STAGEDIR}${DATADIR}/acronyms-o

.include <bsd.port.mk>
