# New ports collection makefile for:	automake
# Version required:	1.2
# Date created:		15 March 1997
# Whom:			FUJIMOTO Kensaku <fujimoto@oscar.elec.waseda.ac.jp>
#
# $Id: Makefile,v 1.4 1997/09/19 07:13:28 tg Exp $
#

DISTNAME=	automake-1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	fujimoto@oscar.elec.waseda.ac.jp

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=/usr/bin/perl
STRIP=		 # none
pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi

.include <bsd.port.mk>
