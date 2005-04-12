# New ports collection makefile for: uniksc
# Date created:		15 Oct 2000
# Whom:			cjh
#
# $FreeBSD$
#

PORTNAME=	uniksc
PORTVERSION=	0.9
CATEGORIES=	korean converters
MASTER_SITES=	ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	cjh@freebsd.org
COMMENT=	Converts data between Korean KSC-5601 and Unicode 3.0 UTF-16

INSTALLS_SHLIB=	YES

.if ${MACHINE_ARCH:L} == "amd64"
CFLAGS+=	"-fPIC"
.endif

.include <bsd.port.mk>
