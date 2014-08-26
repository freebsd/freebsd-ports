# Created by: ijliao
# $FreeBSD$

PORTNAME=	inilib
PORTVERSION=	1.0.7b3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.0.7

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ lib which provides a method of saving the "state" of a program

GNU_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} -e '/echo.*RANLIB/,+1d' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
