# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	peg-e
PORTVERSION=	1.1.2
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/peg-e/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Peg elimination game

USE_BZIP2=	yes
USE_QT4=	corelib gui moc_build qmake_build rcc_build
INSTALLS_ICONS=	yes
DESTDIRNAME=	INSTALL_ROOT

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS} \
		PREFIX=${PREFIX} ${PORTNAME}.pro

.include <bsd.port.mk>
