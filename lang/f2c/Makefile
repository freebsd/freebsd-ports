# Ports collection makefile for:	f2c-freebsd
# Date created:				28 DEC 1998
# Whom:					Steven G. Kargl
#
# $FreeBSD$
#

PORTNAME=	f2c
PORTVERSION=	3.0.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	lioux
DISTNAME=	f2c-freebsd.3.0.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fortran-to-C converter and its run-time libraries

.include <bsd.port.pre.mk>

.if (${ARCH} == "alpha")
pre-configure:
	@${CP} ${FILESDIR}/f2c.h.alpha ${WRKSRC}/f2c/f2c.h
.endif

ALL_TARGET=	depend all

MAN1=		f2c.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/f2c/f2c ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/f2c/f2c.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/f2c/f2c.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/libf2c/libf2c.* ${PREFIX}/lib
	${LN} -sf libf2c.so.2 ${PREFIX}/lib/libf2c.so

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
