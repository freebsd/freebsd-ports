# New ports collection makefile for:    S-Lang library
# Version required:     0.99-38
# Date created:         11 July 1996
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=	slang1.2.2
PKGNAME=	libslang-1.2.2
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v1.2/

MAINTAINER=	xaa@xaa.iae.nl

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/slang

ALL_TARGET=	all elf
INSTALL_TARGET=	install install-elf

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
