# New ports collection makefile for:	distorm
# Date created:				13 May 2008
# Whom:					bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	distorm
PORTVERSION=	3.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		LOCAL/bf
DISTNAME=	${PORTNAME}${PORTVERSION:R:R}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Fast x86 and x86-64 disassembler library

LICENSE=	GPLv3

USE_ZIP=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/distorm3/build/linux
ALL_TARGET=	clib
PLIST_FILES=	bin/disasm lib/libdistorm3.a lib/libdistorm3.so

post-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/disasm ${WRKSRC}/../../linuxproj/main.c \
		${WRKSRC}/libdistorm3.a

do-install:
	( cd ${WRKSRC} && ${INSTALL_DATA} libdistorm3.a libdistorm3.so ${PREFIX}/lib \
	&& ${INSTALL_PROGRAM} disasm ${PREFIX}/bin )

.include <bsd.port.mk>
