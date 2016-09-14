# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	epoch
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}${PORTVERSION}src

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Small and handy timeline application

LINCENSE=	GPLv3
PROJECTHOST=	gepoch

BROKEN=		Unfetchable (google code has gone away)

USES=		qmake zip
USE_QT4=	gui moc_build rcc_build

PLIST_FILES=	bin/${PORTNAME} share/pixmaps/${PORTNAME}.png

WRKSRC=		${WRKDIR}

DESKTOP_ENTRIES="Epoch" "Timeline application" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" "${PORTNAME}" \
		"" true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/epoch ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA}	${WRKSRC}/images/epoha.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
