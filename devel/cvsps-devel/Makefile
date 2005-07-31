# ex:ts=8
# Ports collection makefile for:	cvsps
# Date Created:			Feb 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cvsps
DISTVERSION=	2.1
CATEGORIES=	devel
MASTER_SITES=	http://www.cobite.com/cvsps/
PKGNAMESUFFIX?=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CVS patchsets

CONFLICTS=	cvsps-1.*

USE_GMAKE=	yes

MAN1=		cvsps.1
PLIST_FILES=	bin/cvsps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsps ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cvsps.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
