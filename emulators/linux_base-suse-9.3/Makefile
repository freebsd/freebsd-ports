# New ports collection makefile for:    linux_lib
# Version required:	1.0
# Date created:         
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.4 1995/11/08 15:05:22 erich Exp $
#

DISTNAME=	linux_lib
PKGNAME=	linux_lib-1.0
CATEGORIES=	emulation

MAINTAINER=	erich@FreeBSD.org

PREFIX=		/compat/linux/
WRKSRC=		${WRKDIR}

pre-install:
	@[ -d ${PREFIX} ] || mkdir -p ${PREFIX}

.include <bsd.port.mk>
