# New ports collection makefile for:    S-Lang library
# Version required:     0.99-33
# Date created:         11 July 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.6 1996/05/04 10:40:23 ache Exp $
#

DISTNAME=       slang0.99-33
PKGNAME=        libslang-0.99-33
CATEGORIES+=	devel
MASTER_SITES=   ftp://space.mit.edu/pub/davis/slang/
GNU_CONFIGURE=  yes

MAINTAINER=     ache@FreeBSD.org

ALL_TARGET=     all elf
INSTALL_TARGET= install install-elf
WRKSRC=         ${WRKDIR}/slang

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
