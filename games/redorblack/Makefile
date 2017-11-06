# Created by: buratello@easy.com
# $FreeBSD$

PORTNAME=	redorblack
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	SF/redorb/

MAINTAINER=	buratello@easy.com
COMMENT=	Simple card game to test fortune and probability theory

LICENSE=	BSD2CLAUSE

BROKEN_powerpc64=	fails to compile: deckClass.h: error: random: No such file or directory

PLIST_FILES=	bin/redorblack

do-build:
	${CXX} ${CXXFLAGS} -o ${WRKSRC}/redorblack ${WRKSRC}/redorblack.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/redorblack ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
