# Created by: Kai Wang <kaiwang27@gmail.com>
# $FreeBSD$

PORTNAME=	qtads
PORTVERSION=	2.1.6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-2.x/${PORTVERSION}

MAINTAINER=	kaiwang27@gmail.com
COMMENT=	Cross-platform multimedia interpreter for TADS games

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT4=	gui moc_build network qmake_build rcc_build uic_build
USE_SDL=	sdl mixer sound

QMAKEFLAGS+=	QMAKE_CFLAGS_RELEASE="" QMAKE_CXXFLAGS_RELEASE=""

PLIST_FILES=	bin/qtads

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
