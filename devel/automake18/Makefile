# New ports collection makefile for:	automake
# Version required:	1.3
# Date created:		15 March 1997
# Whom:			FUJIMOTO Kensaku <fujimoto@oscar.elec.waseda.ac.jp>
#
# $Id: Makefile,v 1.7 1998/09/23 16:11:36 vanilla Exp $
#

DISTNAME=	automake-1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	fujimoto@oscar.elec.waseda.ac.jp

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PERL5}
USE_PERL5=	yes

STRIP=		 # none

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/automake.info ${PREFIX}/info/dir

.include <bsd.port.mk>
