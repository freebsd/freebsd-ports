# New ports collection makefile for:	m68kbinutils
# Date created:		7 July 1998
# Whom:			Jerry Hicks <jhicks@glenatl.glenayre.com>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	2.9.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	binutils
PKGNAMEPREFIX=	m68k

MAINTAINER=	gehicks@cisco.com

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--target=m68k-coff

MAN1=		m68k-coff-ar.1 m68k-coff-nlmconv.1 m68k-coff-c++filt.1   \
		m68k-coff-nm.1 m68k-coff-objdump.1 m68k-coff-ranlib.1    \
		m68k-coff-size.1 m68k-coff-strings.1 m68k-coff-strip.1   \
		m68k-coff-objcopy.1 m68k-coff-as.1 m68k-coff-addr2line.1 \
		m68k-coff-ld.1

.include <bsd.port.mk>
