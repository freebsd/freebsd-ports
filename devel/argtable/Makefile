# ex:ts=8
# Ports collection makefile for:	argtable
# Date created:			Dec 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	argtable
PORTVERSION=	2.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ANSI C library for parsing GNU style command line arguments

WRKSRC=		${WRKDIR}/${PORTNAME}2

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN3=		argtable2.3

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/argtable2.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/libargtable2.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/doc/argtable2.3 ${MANPREFIX}/man/man3
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in argtable2-intro.html argtable2-intro.pdf argtable2-intro.ps \
	argtable2.html argtable2.pdf argtable2.ps
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for file in Makefile README.txt echo.c ls.c mv.c myprog.c myprog_C89.c \
	rm.c uname.c
	${INSTALL_DATA} ${WRKSRC}/example/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
