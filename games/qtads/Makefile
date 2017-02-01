# Created by: Kai Wang <kaiwang27@gmail.com>
# $FreeBSD$

PORTNAME=	qtads
PORTVERSION=	2.1.6
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-2.x/${PORTVERSION}

MAINTAINER=	kaiwang27@gmail.com
COMMENT=	Cross-platform multimedia interpreter for TADS games

LICENSE=	GPLv2

USES=		gmake pkgconfig qmake tar:bzip2
USE_QT4=	gui moc_build network rcc_build uic_build
USE_SDL=	sdl mixer sound

QMAKE_ARGS+=	QMAKE_CFLAGS_RELEASE="" QMAKE_CXXFLAGS_RELEASE=""

PLIST_FILES=	bin/qtads

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
