# New ports collection makefile for:    S-Lang library
# Version required:     0.99-35
# Date created:         11 July 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.5 1996/10/24 01:41:30 ache Exp $
#

DISTNAME=       slang0.99-35
PKGNAME=        libslang-0.99.35
CATEGORIES+=	devel
MASTER_SITES=   ftp://space.mit.edu/pub/davis/slang/

MAINTAINER=     ache@FreeBSD.org

GNU_CONFIGURE=  yes
ALL_TARGET=     all elf
INSTALL_TARGET= install install-elf
WRKSRC=         ${WRKDIR}/slang

post-install:
	rm -f ${PREFIX}/lib/libslang.so.99.3[34]
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
