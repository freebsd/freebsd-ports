# Created by: arved
# $FreeBSD$

PORTNAME=	qnetwalk
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	http://qt.osdn.org.ua/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Qt-version of the NetWalk game

LICENSE=	GPLv2

USE_QT4=	corelib gui qmake_build moc_build rcc_build
USE_SDL=	mixer
DESTDIRNAME=	INSTALL_ROOT

PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/games|$$$${PREFIX}/bin|; \
		s|/usr/share/man|$$$${PREFIX}/man|; \
		s|/usr/share|$$$${PREFIX}/share|; \
		/INSTALLS.*menu/ d' ${WRKSRC}/${PORTNAME}.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
