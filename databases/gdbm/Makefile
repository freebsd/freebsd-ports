# New ports collection makefile for: gdbm
# Version required:	1.8.0
# Date created:		8 Apr 1996
# Whom:			Brent J. Nordquist <bjn@visi.com>
#
# $Id: Makefile,v 1.7 1999/06/05 22:28:14 mharo Exp $
#

DISTNAME=	gdbm-1.8.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gdbm

MAINTAINER=	bjn@visi.com

USE_LIBTOOL=	yes
MAN3=		gdbm.3

post-install:
	@install-info ${PREFIX}/info/gdbm.info ${PREFIX}/info/dir

.include <bsd.port.mk>
