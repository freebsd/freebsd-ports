# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	schiff
PORTVERSION=	16
PORTREVISION=	7
CATEGORIES=	games python
MASTER_SITES=	SF/pygamebook/${PORTNAME:S/s/S/}/${PORTNAME}${PORTVERSION}.py/ \
		SF/nemysisfreebsdp/games/:icons
DISTFILES=	${PORTNAME}${DISTVERSION}.py \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Steer your ship(s) with the keyboard

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2+

RUN_DEPENDS=	${PYGAME}

USES=		python:2.7,run shebangfix
SHEBANG_FILES=	schiff.py
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_ARCH=	yes

SUB_FILES=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png \
		%%DATADIR%%/${PORTNAME}.py

DESKTOP_ENTRIES="Schiff" "" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" ""

do-extract:
	@${CP} ${_DISTDIR}/schiff${PORTVERSION}.py ${WRKSRC}/${PORTNAME}.py

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
