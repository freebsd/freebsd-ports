# New ports collection makefile for:    S-Lang library
# Date created:         11 July 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	libslang
PORTVERSION=	1.4.0
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v1.4/
DISTNAME=	slang-${PORTVERSION}

MAINTAINER=	xaa+ports@timewasters.nl

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
#WRKSRC=		${WRKDIR}/slang

ALL_TARGET=	all elf
INSTALL_TARGET=	install install-elf

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
