# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	yell
PORTVERSION=	1.1
CATEGORIES=	audio
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line pc speaker bell

PLIST_FILES=	bin/yell

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	SUID
SUID_DESC=	Use suid to allow execution as non root

.include <bsd.port.options.mk>

do-build:
	${CC} ${WRKSRC}/yell.c ${CFLAGS} -o ${WRKSRC}/${PORTNAME}

do-install:
.if ${PORT_OPTIONS:MSUID}
	${INSTALL_PROGRAM} -m 4110 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.else
	${INSTALL_PROGRAM} -m 0100 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.endif

.include <bsd.port.mk>
