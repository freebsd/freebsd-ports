# ex:ts=8
# Ports collection makefile for:  bison
# Date created:			  27 Mar 1999
# Whom:				  Jerry Hicks
#
# $FreeBSD$
#

DISTNAME=		bison-1.28
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	bison

MAINTAINER=		wghicks@bellsouth.net
MAINTAINER=		obrien@NUXI.com

GNU_CONFIGURE=		yes
MAN1=			bison.1

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' \/usr\/share\/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/bison.info ${PREFIX}/info/dir

.include <bsd.port.mk>
