# New ports collection makefile for:    linux_devel
# Version required:	0.1
# Date created:         Nov 26 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.3 1997/04/14 19:04:02 erich Exp $
#

DISTNAME=	linux_devel-0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	erich@FreeBSD.org

RUN_DEPENDS=	/compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

PREFIX=		/compat/linux
NO_MTREE=	yes
NO_BUILD=	yes
NO_EXTRACT=	yes
NO_WRKDIR=	yes

pre-install:
	@[ -d ${PREFIX} ] || ${MKDIR} ${PREFIX}

do-install:
	zcat ${DISTDIR}/${DISTNAME}.tar.gz |(cd ${PREFIX}; pax -r)

.include <bsd.port.mk>
