# New ports collection makefile for:    linux_lib
# Version required:	1.0
# Date created:         
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.3 1995/11/06 15:18:05 erich Exp $
#

DISTNAME=	linux_lib
CATEGORIES=	emulators
MAINTAINER=	erich@FreeBSD.org

PREFIX=		/compat/linux/
WRKSRC=		${WRKDIR}

pre-install:
	@[ -d ${PREFIX} ] || mkdir -p ${PREFIX}

.include <bsd.port.mk>
