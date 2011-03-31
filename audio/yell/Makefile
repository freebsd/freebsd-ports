# New ports collection makefile for:   yell
# Date created:		10 August 2004
# Whom:			Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	yell
PORTVERSION=	1.1
CATEGORIES=	audio
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command line pc speaker bell

MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/yell

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS=	SUID	"Set the setuid bit on the yell program"	off

do-build:
	${CC} ${WRKSRC}/yell.c ${CFLAGS} -o ${WRKSRC}/${PORTNAME}

do-install:
.if defined(WITH_SUID)
	${INSTALL_PROGRAM} -m 4110 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.else
	${INSTALL_PROGRAM} -m 0100 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.endif

.include <bsd.port.mk>
