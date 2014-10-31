# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	schiff
PORTVERSION=	16
PORTREVISION=	2
CATEGORIES=	games python
MASTER_SITES=	SF/pygamebook/${PORTNAME:S/s/S/}/${PORTNAME}${PORTVERSION}.py/ \
		SF/nemysisfreebsdp/games/:icons
DISTFILES=	${PORTNAME}${DISTVERSION}.py \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Steer your ship(s) with the keyboard

LICENSE=	GPLv2 # or later

RUN_DEPENDS=	${PYGAME}

USES=		python:2,run
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png \
		%%DATADIR%%/${PORTNAME}.py

DESKTOP_ENTRIES="Schiff" "" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" ""

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${_DISTDIR}/schiff${PORTVERSION}.py \
		${STAGEDIR}${DATADIR}/${PORTNAME}.py

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
