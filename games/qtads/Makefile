# Created by: Kai Wang <kaiwang27@gmail.com>
# $FreeBSD$

PORTNAME=	qtads
PORTVERSION=	2.1.7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-2.x/${PORTVERSION}

MAINTAINER=	kaiwang27@gmail.com
COMMENT=	Cross-platform multimedia interpreter for TADS games

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BROKEN=		fails to build

USES=		gmake pkgconfig qmake qt:4 tar:bzip2
USE_QT=		gui moc_build network rcc_build uic_build
USE_SDL=	sdl mixer sound

QMAKE_ARGS+=	QMAKE_CFLAGS_RELEASE="" QMAKE_CXXFLAGS_RELEASE=""

PLIST_FILES=	bin/qtads

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
