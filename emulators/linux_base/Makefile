# New ports collection makefile for:    linux_lib
# Version required:	1.0
# Date created:         
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.5 1995/11/14 13:03:13 asami Exp $
#

DISTNAME=	linux_lib
PKGNAME=	linux_lib-1.0
CATEGORIES=	emulation

MAINTAINER=	erich@FreeBSD.org

PREFIX=		/compat/linux/
WRKSRC=		${WRKDIR}
NO_MTREE=	yes

pre-install:
	@[ -d ${PREFIX} ] || mkdir -p ${PREFIX}

.include <bsd.port.mk>
