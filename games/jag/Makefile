# New ports collection makefile for:	jag
# Date created:		03 Jul 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jag
PORTVERSION=	0.2.4
CATEGORIES=	games
MASTER_SITES=	http://jag.xlabsoft.com/files/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2d arcade-puzzle game like KDiamonds

USE_ZIP=	yes
USE_SDL=	sdl mixer

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build uic_build moc_build rcc_build \
		corelib svg xml opengl network
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src/jag

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/games/jag|${DATADIR}|' \
		${WRKSRC}/gamewidget.cpp ${WRKSRC}/Game.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/Game.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX} Game.pro

.include <bsd.port.mk>
