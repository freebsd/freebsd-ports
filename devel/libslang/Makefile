# New ports collection makefile for:    S-Lang library
# Version required:     0.99-34
# Date created:         11 July 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.2 1996/07/12 10:24:04 asami Exp $
#

DISTNAME=       slang0.99-34
PKGNAME=        libslang-0.99.34
CATEGORIES+=	devel
MASTER_SITES=   ftp://space.mit.edu/pub/davis/slang/

MAINTAINER=     ache@FreeBSD.org

GNU_CONFIGURE=  yes
ALL_TARGET=     all elf
INSTALL_TARGET= install install-elf
WRKSRC=         ${WRKDIR}/slang

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
