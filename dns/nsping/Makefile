# New ports collection makefile for:	nsping
# Version required:	0.8
# Date created:		04 March 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$

DISTNAME=	nsping
PKGNAME=	nsping-0.8
CATEGORIES=	net
MASTER_SITES=	http://www.enteract.com/~tqbf/

MAINTAINER=	kris@FreeBSD.org

WRKSRC=		${WRKDIR}/${PKGNAME}

MAN8=		nsping.8

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/nsping ${PREFIX}/sbin
		${INSTALL_DATA} ${WRKSRC}/nsping.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
