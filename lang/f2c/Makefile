# Ports collection makefile for:	f2c-freebsd
# Version required: 			2.0.1
# Date created:				28 DEC 1998
# Whom:					Steven G. Kargl
#
# $FreeBSD$
#

DISTNAME=	f2c-freebsd.2.0.1
PKGNAME=	f2c-2.0.1
CATEGORIES=	lang
MASTER_SITES=	ftp://troutmask.apl.washington.edu/pub/

MAINTAINER=	kargl@troutmask.apl.washington.edu

.include <bsd.port.pre.mk>

.if (${ARCH} == "alpha")
pre-configure:
	@${CP} ${FILESDIR}/f2c.h.alpha ${WRKSRC}/f2c/f2c.h
.endif

ALL_TARGET=   depend all

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
