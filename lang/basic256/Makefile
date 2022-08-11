PORTNAME=	basic256
PORTVERSION=	2.0.0.11
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	SF/kidbasic/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Easy to use BASIC language and IDE for education

LICENSE=	GPLv2

BUILD_DEPENDS=	flex:textproc/flex \
		sqlite3:databases/sqlite3
LIB_DEPENDS=	libespeak-ng.so:audio/espeak-ng

USES=		bison compiler:c++11-lib dos2unix gl qmake qt:5 sdl
DOS2UNIX_FILES=	BASIC256.pro Interpreter.cpp
USE_GL+=	gl
USE_QT=		buildtools core gui multimedia network printsupport sql widgets serialport
USE_SDL=	sdl mixer
QMAKE_ARGS+=	LOCALBASE="${LOCALBASE}"
QMAKE_SOURCE_PATH=	BASIC256.pro

#MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-stage:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/basic256

.include <bsd.port.mk>
