# New ports collection makefile for:    linux_lib
# Version required:	2.0
# Date created:         
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.7 1995/11/22 11:48:12 asami Exp $
#

DISTNAME=	linux_lib-2.0
PKGNAME=	linux_lib-2.0
CATEGORIES=	emulators

MAINTAINER=	erich@FreeBSD.org

PREFIX=		/compat/linux/
WRKSRC=		${WRKDIR}
NO_MTREE=	yes

pre-install:
	@[ -d ${PREFIX} ] || mkdir -p ${PREFIX}

.include <bsd.port.mk>
