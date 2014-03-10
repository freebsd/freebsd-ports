# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jag
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://jag.xlabsoft.com/files/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME:C/src/data/}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D arcade-puzzle game like KDiamonds

USES=		dos2unix zip
USE_SDL=	sdl mixer
DOS2UNIX_FILES=	Game.pro
USE_XORG=	x11

USES=		qmake
USE_QT4=	uic_build moc_build rcc_build \
		corelib svg xml opengl network

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/games/jag|${DATADIR}|' \
		${WRKSRC}/main.cpp ${WRKSRC}/Game.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/Game.pro

post-install:
	cd ${WRKDIR}/${DISTNAME:C/src/data/} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
