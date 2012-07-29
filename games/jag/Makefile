# New ports collection makefile for:	jag
# Date created:		03 Jul 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

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

USE_ZIP=	yes
USE_SDL=	sdl mixer

USE_QT4=	qmake_build uic_build moc_build rcc_build \
		corelib svg xml opengl network
MAKE_JOBS_SAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/games/jag|${DATADIR}|' \
		${WRKSRC}/main.cpp ${WRKSRC}/Game.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/Game.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} Game.pro

post-install:
	${MKDIR} ${DATADIR}
	cd ${WRKDIR}/${DISTNAME:C/src/data/} && ${COPYTREE_SHARE} data ${DATADIR}/

.include <bsd.port.mk>
