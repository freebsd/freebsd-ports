# New ports collection makefile for:	automake
# Version required:	1.2
# Date created:		15 March 1997
# Whom:			FUJIMOTO Kensaku <fujimoto@oscar.elec.waseda.ac.jp>
#
# $Id: Makefile,v 1.3 1997/06/13 20:01:42 max Exp $
#

DISTNAME=	automake-1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	fujimoto@oscar.elec.waseda.ac.jp

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=/usr/bin/perl

post-install:
	@ ${RM} -f ${PREFIX}/info/automake.info-1
	@ ${RM} -f ${PREFIX}/info/automake.info-2

.include <bsd.port.mk>
