# New ports collection makefile for:	m68k-newlib-1.8.1
# Version required:	1.8.1
# Date created:		7 July 1998
# Whom:			Jerry Hicks <jhicks@glenatl.glenayre.com>
#
# $Id$
#

DISTNAME=	newlib-1.8.1
PKGNAME=	m68knewlib-1.8.1
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.cygnus.com/pub/newlib/

MAINTAINER=	jhicks@glenatl.glenayre.com

BUILD_DEPENDS=	m68k-coff-gcc:${PORTSDIR}/devel/m68kgcc

NO_PACKAGE=	please compile locally
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

TARGET=		m68k-coff

CONFIGURE_ARGS=	--target=${TARGET} --with-gnu-as --with-gnu-ld

do-build:
	(cd ${WRKSRC} && ${GMAKE} CFLAGS="-O -pipe")

.include <bsd.port.mk>
