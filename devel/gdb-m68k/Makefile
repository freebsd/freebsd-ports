# New ports collection makefile for:    m68kgdb
# Date created:         7 Jul 98
# Whom:                 Jerry Hicks <Jerry.Hicks@Glenayre.com>
#
# $FreeBSD$
#

PORTNAME=	gdb
PORTVERSION=	4.18
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gdb
PKGNAMEPREFIX=	m68k

MAINTAINER=	gehicks@cisco.com

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS= --target=m68k-coff

MAN1=		m68k-coff-gdb.1

INSTALL_TARGET=install

do-install:
	(cd ${WRKSRC}/gdb && ${GMAKE} ${INSTALL_TARGET})

.include <bsd.port.mk>
