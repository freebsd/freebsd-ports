# New ports collection makefile for:	xdl
# Version required:     2.1
# Date created:         17 July 1995
# Whom:                 asami
#
# $Id: Makefile,v 1.4 1995/05/04 02:08:19 smace Exp $
#

DISTNAME=	xdl-2.1
CATEGORIES+=	graphics x11
# supposed to be ftp.uoknor.edu, but the new machine doesn't have it
MASTER_SITES=	ftp://romulus.ucs.uoknor.edu/src/X11R5/

MAINTAINER=	asami@FreeBSD.ORG

USE_X11=	yes

post-install:
	gzip -9nf ${PREFIX}/man/man1/xdl.1

.include <bsd.port.mk>
