# New ports collection makefile for:    linux_lib
# Version required:	2.1
# Date created:         
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.9 1996/10/28 15:20:13 erich Exp $
#

DISTNAME=	linux_lib-2.1
CATEGORIES=	emulators

MAINTAINER=	erich@FreeBSD.org

PREFIX=		/compat/linux/
WRKSRC=		${WRKDIR}
NO_MTREE=	yes

pre-install:
	@[ -d ${PREFIX} ] || ${MKDIR} ${PREFIX}

.include <bsd.port.mk>
