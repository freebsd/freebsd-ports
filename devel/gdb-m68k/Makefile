# New ports collection makefile for:    m68kgdb
# Version required:     4.17
# Date created:         23 Jun 98
# Whom:                 Pedro Giffuni <pgiffuni@fps.biblos.unal.edu.co>
#
# $Id$
#

DISTNAME=	gdb-4.17
PKGNAME=	m68kgdb-4.17
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	jhicks@mail.glenatl.glenayre.com

NO_PACKAGE=	please compile locally
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
TARGET=		m68k-coff
CONFIGURE_ARGS= --target=$(TARGET)

MAN1=		m68k-coff-gdb.1

INSTALL_TARGET=install

do-install:
	cd ${WRKSRC}/gdb && ${GMAKE} ${INSTALL_TARGET}

.include <bsd.port.mk>
