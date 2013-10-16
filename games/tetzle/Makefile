# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	tetzle
PORTVERSION=	2.0.2
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/tetzle/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Jigsaw puzzle with tetrominoes

USE_BZIP2=	yes
USE_QT4=	corelib gui moc_build opengl qmake_build rcc_build xml
INSTALLS_ICONS=	yes
DESTDIRNAME=	INSTALL_ROOT

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS} \
		PREFIX=${PREFIX} tetzle.pro

post-install:
	${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
