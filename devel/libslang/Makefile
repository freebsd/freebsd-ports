# New ports collection makefile for:    S-Lang library
# Version required:     0.99-38
# Date created:         11 July 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.11 1998/02/26 03:41:40 steve Exp $
#

DISTNAME=       slang0.99-38
PKGNAME=        libslang-0.99.38
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.clara.net/pub/unix/Usenet/

MAINTAINER=     ports@FreeBSD.org

GNU_CONFIGURE=  yes
ALL_TARGET=     all elf
INSTALL_TARGET= install install-elf
WRKSRC=         ${WRKDIR}/slang

post-install:
	@rm -f ${PREFIX}/lib/libslang.so.99.3[348]
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
