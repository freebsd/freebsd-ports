# New ports collection makefile for:	xdl
# Version required:     2.1
# Date created:         17 July 1995
# Whom:                 asami
#
# $Id: Makefile,v 1.1.1.1 1995/07/18 00:32:33 asami Exp $
#

DISTNAME=	xdl-2.1
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://ftp.uoknor.edu/src/X11R5/

MAINTAINER=	asami@FreeBSD.ORG

USE_X11=	yes

post-install:
	gzip -9nf ${PREFIX}/man/man1/xdl.1

.include <bsd.port.mk>
