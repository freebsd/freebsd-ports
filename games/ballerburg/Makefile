# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ballerburg
PORTVERSION=	1.2.0
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/baller/ \
		LOCAL/ehaupt:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-icons-1${EXTRACT_SUFX}:icons

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Two players, two castles, and a hill in between

LICENSE=	GPLv3+

GNU_CONFIGURE=	yes
NLS_USES=	gettext
USES=		cmake:insource sdl
USE_SDL=	sdl

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

DESKTOP_ENTRIES="Ballerburg" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/ballerburg.png" \
		"${PORTNAME}" \
		"" \
		false

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-icons-1/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
