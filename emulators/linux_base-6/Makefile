# New ports collection makefile for:    linux_lib
# Version required:	2.1
# Date created:         
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.8 1996/03/29 14:46:25 erich Exp $
#

DISTNAME=	linux_lib-2.1
CATEGORIES=	emulators

MAINTAINER=	erich@FreeBSD.org

PREFIX=		/compat/linux/
WRKSRC=		${WRKDIR}
NO_MTREE=	yes

pre-install:
	@[ -d ${PREFIX} ] || mkdir -p ${PREFIX}

.include <bsd.port.mk>
