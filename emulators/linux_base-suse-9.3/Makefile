# New ports collection makefile for:    linux_lib
# Version required:	2.1
# Date created:         
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.11 1996/11/26 23:09:12 erich Exp $
#

DISTNAME=	linux_lib-2.2
CATEGORIES=	emulators
MASTER_SITES=	ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/

MAINTAINER=	erich@FreeBSD.org

PREFIX=		/compat/linux
NO_MTREE=	yes
NO_BUILD=	yes
NO_EXTRACT=	yes
NO_WRKDIR=	yes

pre-install:
	@[ -d ${PREFIX} ] || ${MKDIR} ${PREFIX}

do-install:
	@zcat ${DISTDIR}${DISTNAME}.tar.gz |(cd ${PREFIX}; pax -r)

.include <bsd.port.mk>
