# Created by: ijliao
# $FreeBSD$

PORTNAME=	gplcver
PORTVERSION=	2.12.a
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}${PORTVERSION:E}/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Verilog HDL simulator

DEPRECATED=	Abandonware using sys/dir.h
EXPIRATION_DATE=	2019-07-12

USES=		tar:bzip2 gmake

BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	makefile.freebsd

PLIST_FILES=	bin/cver

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cver ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
