# New ports collection makefile for:    gdbsco
# Version required:     4.16
# Date created:         26 Mar 97
# Whom:                 Pedro Giffuni <pgiffuni@fps.biblos.unal.edu.co>
#
# $Id$
#

DISTNAME=       gdb-4.16
PKGNAME=	m68kgdb-4.16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	jhicks@atlanta.glenayre.com

NO_PACKAGE=	 please compile locally
GNU_CONFIGURE=	yes
TARGET=		m68k-coff
CONFIGURE_ARGS= --target=$(TARGET)

MAN1=		m68k-coff-gdb.1

INSTALL_TARGET=install

do-install:
	cd ${WRKSRC}/gdb && make ${INSTALL_TARGET}

.include <bsd.port.mk>
