# New ports collection makefile for:	m68kgcc-2.8.1
# Version required:	2.8.1
# Date created:		7 July 1998
# Whom:			Jerry Hicks <jhicks@glenatl.glenayre.com>
#
# $Id: Makefile,v 1.6 1998/11/24 03:36:49 steve Exp $
#

DISTNAME=	gcc-2.8.1
PKGNAME=	m68kgcc-2.8.1
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gcc

MAINTAINER=	Jerry.Hicks@Glenayre.com

BUILD_DEPENDS=	m68k-coff-as:${PORTSDIR}/devel/m68kbinutils \
		m68k-coff-ld:${PORTSDIR}/devel/m68kbinutils
RUN_DEPENDS=	m68k-coff-as:${PORTSDIR}/devel/m68kbinutils \
		m68k-coff-ld:${PORTSDIR}/devel/m68kbinutils

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--target=m68k-coff --with-gnu-as --with-gnu-ld

MAKE_FLAGS=	LANGUAGES="c c++" SUBDIRS="cp" -f

MAN1=		cccp.1 m68k-coff-g++.1 m68k-coff-gcc.1

.include <bsd.port.mk>
