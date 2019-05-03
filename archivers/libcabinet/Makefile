# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcabinet
PORTVERSION=	0.30
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	http://www.bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable library and utility to use Microsoft cabinet files (.cab)

USES=		uidfix
USE_LDCONFIG=	yes
SRCFILE=	${WRKSRC}/listcab.cpp
PROGFILE=	${SRCFILE:S/.cpp$//}
MAKE_ENV=	WITHOUT_PROFILE=yes __MAKE_CONF=/dev/null SRCCONF=/dev/null

post-build:
	${CXX} ${CXXFLAGS} -o ${PROGFILE} ${SRCFILE} -L${WRKSRC} -lcabinet -lz

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/cabinet

post-install:
	${INSTALL_PROGRAM} ${PROGFILE} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
