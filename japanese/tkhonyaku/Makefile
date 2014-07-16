# Created by: Daichi GOTO
# $FreeBSD$

PORTNAME=	tkhonyaku
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://www.yk.rim.or.jp/~kawagisi/

MAINTAINER=	daichi@FreeBSD.org
COMMENT=	Yet another Honyaku-Damashii client with rich functionality

RUN_DEPENDS=	${LOCALBASE}/bin/wish8.0jp:${PORTSDIR}/japanese/tk80

USES=		perl5
USE_PERL5=	build
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/usr/local/tkhonyaku|${PREFIX}/tkhonyaku|g' \
		${WRKSRC}/tkhonyaku ${WRKSRC}/tkhonyaku-readme

do-install:
	${INSTALL_DATA} ${WRKSRC}/tkhonyaku.gif ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tkhonyaku.xpm ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/colors.gif ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tkhonyaku ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/tkhonyaku-readme ${STAGEDIR}${PORTDOCS}${DOCSDIR}

.include <bsd.port.mk>
