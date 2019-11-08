# $FreeBSD$

PORTNAME=	basic256
PORTVERSION=	1.1.4.0
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	SF/kidbasic/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Easy to use BASIC language and IDE for education

LICENSE=	GPLv2

BUILD_DEPENDS=	espeak:audio/espeak \
		sqlite3:databases/sqlite3 \
		flex:textproc/flex

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		bison compiler:c++11-lang dos2unix qmake qt:5 sdl
USE_SDL=	sdl mixer
USE_QT=		buildtools core gui multimedia network printsupport sql widgets serialport
QMAKE_ARGS+=	LOCALBASE="${LOCALBASE}"
QMAKE_SOURCE_PATH=	BASIC256.pro

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/BASIC256.pro

.include <bsd.port.mk>
