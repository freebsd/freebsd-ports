# New ports collection makefile for:	m68kgcc
# Date created:		7 July 1998
# Whom:			Jerry Hicks <jhicks@glenatl.glenayre.com>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.8.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gcc
PKGNAMEPREFIX=	m68k

MAINTAINER=	gehicks@cisco.com

BUILD_DEPENDS=	m68k-coff-as:${PORTSDIR}/devel/binutils-m68k \
		m68k-coff-ld:${PORTSDIR}/devel/binutils-m68k
RUN_DEPENDS=	m68k-coff-as:${PORTSDIR}/devel/binutils-m68k \
		m68k-coff-ld:${PORTSDIR}/devel/binutils-m68k

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--target=m68k-coff --with-gnu-as --with-gnu-ld

MAKE_FLAGS=	LANGUAGES="c c++" SUBDIRS="cp" -f

MAN1=		cccp.1 m68k-coff-g++.1 m68k-coff-gcc.1

.include <bsd.port.mk>
