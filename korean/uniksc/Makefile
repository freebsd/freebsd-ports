# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	uniksc
PORTVERSION=	0.9
CATEGORIES=	korean converters
MASTER_SITES=	ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts data between Korean KSC-5601 and Unicode 3.0 UTF-16

USE_LDCONFIG=	YES
PLIST_FILES=	bin/uniksc include/uniksc.h lib/libuniksc.so.0

.if ${MACHINE_ARCH:L} == "amd64"
CFLAGS+=	"-fPIC"
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
