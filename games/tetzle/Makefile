# New ports collection makefile for:	tetzle
# Date created:		12 Jun 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	tetzle
PORTVERSION=	1.2.1
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/tetzle/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Jigsaw puzzle with tetrominoes

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui moc_build opengl qmake_build rcc_build xml
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		PREFIX=${PREFIX} -spec ${QMAKESPEC} tetzle.pro

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tetzle ${PREFIX}/bin

.include <bsd.port.mk>
