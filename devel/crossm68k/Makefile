# New ports collection makefile for:	crossm68k
# Version required:    2.0
# Date created:        7 July 1997
# Whom:                Jerry Hicks <jhicks@glenatl.glenayre.com>
#
# $Id: Makefile,v 1.1.1.1 1998/03/16 03:45:00 steve Exp $
#

DISTNAME=	crossm68k-2.0
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	Jerry.Hicks@Glenayre.com

# this dependency will cause m68kbinutils and m68kgcc to be built as well
BUILD_DEPENDS=	${PREFIX}/m68k-coff/lib/crt0.o:${PORTSDIR}/devel/m68knewlib
RUN_DEPENDS=	m68k-coff-gdb:${PORTSDIR}/devel/m68kgdb

NO_PACKAGE=	limited audience
EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_CHECKSUM=	yes

do-install:	# empty

.include <bsd.port.mk>
