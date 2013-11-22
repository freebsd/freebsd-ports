# Created by: Konstantin Tokarev <annulen@yandex.ru>
# $FreeBSD$

PORTNAME=	openpref
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/OpenPref-Qt4/${PORTNAME}-${PORTVERSION}

MAINTAINER=	annulen@yandex.ru
COMMENT=	Preferans game

USES=		qmake
USE_QT4=	corelib gui moc_build rcc_build uic_build
MAKE_JOBS_UNSAFE=	yes

DESKTOP_ENTRIES="OpenPref" "${COMMENT}" "${DATADIR}/openpref.png" \
		"openpref" "Game;CardGame;" true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/openpref ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/i18n
	${INSTALL_DATA} ${WRKSRC}/openpref_ru.qm ${STAGEDIR}${DATADIR}/i18n
	${INSTALL_DATA} ${WRKSRC}/pics/openpref.png ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
