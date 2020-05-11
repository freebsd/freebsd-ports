# $FreeBSD$

PORTNAME=	basic256
PORTVERSION=	2.0.0.1
CATEGORIES=	lang
MASTER_SITES=	SF/kidbasic/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Easy to use BASIC language and IDE for education

LICENSE=	GPLv2

BUILD_DEPENDS=	espeak:audio/espeak \
		sqlite3:databases/sqlite3 \
		flex:textproc/flex

USES=		bison compiler:c++11-lib dos2unix gl qmake qt:5 sdl
DOS2UNIX_FILES=	BASIC256.pro Interpreter.cpp
USE_SDL=	sdl mixer
USE_GL+=	gl
USE_QT=		buildtools core gui multimedia network printsupport sql widgets serialport
QMAKE_ARGS+=	LOCALBASE="${LOCALBASE}"
QMAKE_SOURCE_PATH=	BASIC256.pro

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
