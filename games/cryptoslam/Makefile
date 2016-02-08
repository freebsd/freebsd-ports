# Created by: ijliao
# $FreeBSD$

PORTNAME=	cryptoslam
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based tool for creating and solving the cryptograms

USES=		ncurses tar:tgz
PLIST_FILES=	bin/cryptoslam

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} cryptogram.cpp cryptoslam.cpp \
		-o ${PORTNAME} ${LDFLAGS} -lncurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
