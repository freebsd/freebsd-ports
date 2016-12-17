# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	yell
PORTVERSION=	1.1
CATEGORIES=	audio
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line pc speaker bell

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	SUID
SUID_DESC=	Use suid to allow execution as non root

SUID_PLIST_FILES=	"@(,,4110) bin/yell"
SUID_PLIST_FILES_OFF=	"@(,,0100) bin/yell"

do-build:
	${CC} ${WRKSRC}/yell.c ${CFLAGS} -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
