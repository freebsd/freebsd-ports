# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	basic256
PORTVERSION=	1.1.4.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF/kidbasic/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Easy to use BASIC language and IDE for education

LICENSE=	GPLv2

BUILD_DEPENDS=	espeak:audio/espeak \
		sqlite3:databases/sqlite3 \
		flex:textproc/flex

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		bison dos2unix qmake
USE_SDL=	sdl mixer
USE_QT5=	buildtools core gui multimedia network printsupport sql widgets serialport
QMAKE_ARGS+=	LOCALBASE="${LOCALBASE}"
QMAKE_SOURCE_PATH=	BASIC256.pro

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/BASIC256.pro

.include <bsd.port.mk>
