# Created by: arved
# $FreeBSD$

PORTNAME=	qnetwalk
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://qt.osdn.org.ua/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Qt-version of the NetWalk game

LICENSE=	GPLv2

USES=		qmake
USE_QT4=	corelib gui moc_build rcc_build
USE_SDL=	mixer

PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/games|$$$${PREFIX}/bin|; \
		s|/usr/share/man|$$$${PREFIX}/man|; \
		s|/usr/share|$$$${PREFIX}/share|; \
		/INSTALLS.*menu/ d' ${WRKSRC}/${PORTNAME}.pro

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
