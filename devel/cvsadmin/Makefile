# ex:ts=8
# Ports collection makefile for:	cvsadmin
# Date Created:			Jun 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cvsadmin
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.cooptel.qc.ca/~limitln/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A simple program to administrate users of a CVS repository

GNU_CONFIGURE=	yes

MAN1=	cvsadmin.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/cvsadmin.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
