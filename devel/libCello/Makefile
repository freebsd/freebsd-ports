# Created by: matthew.closson@gmail.com
# $FreeBSD$

PORTNAME=	libCello
PORTVERSION=	1.1.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://libcello.org/static/

MAINTAINER=	matthew.closson@gmail.com
COMMENT=	Higher level programming in C

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		dos2unix execinfo gmake
DOS2UNIX_FILES=	Makefile

CFLAGS+=	${EXECINFO_CPPFLAGS}

post-patch:
	${REINPLACE_CMD} -E 's| abs\(| labs\(|' ${WRKSRC}/src/*.c

.include <bsd.port.mk>
