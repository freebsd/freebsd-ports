# New ports collection makefile for:	stlport
# Version required:	3.01
# Date Created:		2 December 1998
# Whom:			Josh Gilliam <josh@quick.net>
#
# $Id$
#

DISTNAME=	STLport-3.01
PKGNAME=	stlport-3.01
CATEGORIES=	devel
MASTER_SITES=	http://corp.metabyte.com/~fbp/stl/ \
		ftp://maroon.webmaster.com/pub/STLport/

MAINTAINER=	josh@quick.net

NO_WRKSUBDIR=	yes
GNU_CONFIGURE=	yes
NO_BUILD=	yes

pre-configure:
	chmod +x ${WRKSRC}/configure

do-install:
	${MKDIR} ${PREFIX}/include/stlport

.for include in *.h algorith algorithm deque functional hash_map hash_set \
iterator list map memory numeric queue rope set slist stack utility vector \
xmemory xutility
	${INSTALL_DATA} ${WRKSRC}/${include} ${PREFIX}/include/stlport
.endfor

.include <bsd.port.mk>
