# New ports collection makefile for:	libcabinet
# Date Created:				30 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcabinet
PORTVERSION=	0.30
CATEGORIES=	archivers
MASTER_SITES=	http://trill.cis.fordham.edu/~barbacha/cabinet_library/

MAINTAINER=	sobomax@FreeBSD.org

INSTALLS_SHLIB=	yes

SRCFILE=	${WRKSRC}/listcab.cpp
PROGFILE=	${SRCFILE:S/.cpp$//}

post-build:
	${CXX} ${CXXFLAGS} -o ${PROGFILE} ${SRCFILE} -L${WRKSRC} -lcabinet

pre-install:
	${MKDIR} ${PREFIX}/include/cabinet

post-install:
	${INSTALL_PROGRAM} ${PROGFILE} ${PREFIX}/bin

.include <bsd.port.mk>
