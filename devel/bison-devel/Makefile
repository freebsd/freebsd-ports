# New ports collection makefile for:	bison
# Version required:     1.27
# Date created:		27 Mar 1999
# Whom:			Jerry Hicks
#
# $Id$
#

DISTNAME=		bison-1.27
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	bison

MAINTAINER=		wghicks@bellsouth.net

Y2K=			http://www.gnu.org/software/year2000.html

GNU_CONFIGURE=		yes

MAN1=			bison.1

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' \/usr\/share\/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/bison.info ${PREFIX}/info/dir

.include <bsd.port.mk>
