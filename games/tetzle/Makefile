# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	tetzle
PORTVERSION=	2.0.3
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/tetzle/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Jigsaw puzzle with tetrominoes

USES=		qmake
USE_BZIP2=	yes
USE_QT4=	corelib gui moc_build opengl rcc_build xml
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-install:
	${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
