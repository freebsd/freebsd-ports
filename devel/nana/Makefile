# New ports collection makefile for:    nana
# Version required:     1.09
# Date created:         20th April 1997
# Whom:                 Phil Maker <pjm@cs.ntu.edu.au>
#
# $Id: Makefile,v 1.1.1.1 1997/04/20 19:29:24 pjm Exp $
#

DISTNAME=	nana-1.09
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.ntu.edu.au/pub/nana/

MAINTAINER=	pjm@cs.ntu.edu.au

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

RUN_DEPENDS=	gdb:${PORTSDIR}/devel/gdb

MAN1=		nana.1 nana-clg.1
MAN3= 		nana.3 I.3 DI.3 L.3 DL.3 Q.3 Qstl.3

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi

.include <bsd.port.mk>
