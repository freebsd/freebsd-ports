# New ports collection makefile for:	distorm
# Date created:				13 May 2008
# Whom:					bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	distorm
PORTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		LOCAL/bf
DISTNAME=	${PORTNAME}${PORTVERSION:R:R}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Fast x86 and x86-64 disassembler library

LICENSE=	GPLv3

USE_DOS2UNIX=	yes
USE_ZIP=	yes
USE_LDCONFIG=	yes

BUILD_WRKSRC=	${WRKSRC}/make/linux
ALL_TARGET=	clib
PLIST_FILES=	bin/disasm lib/libdistorm3.a lib/libdistorm3.so

post-build:
	${CC} ${CFLAGS} -o ${BUILD_WRKSRC}/disasm ${WRKSRC}/examples/linux/main.c \
		${BUILD_WRKSRC}/libdistorm3.a

do-install:
	( cd ${BUILD_WRKSRC} && ${INSTALL_DATA} libdistorm3.a libdistorm3.so ${PREFIX}/lib \
	&& ${INSTALL_PROGRAM} disasm ${PREFIX}/bin )

.include <bsd.port.mk>
