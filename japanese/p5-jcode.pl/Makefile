# New ports collection makefile for:	p5-jcode.pl
# Version required:			2.6
# Date created:				26 Jun 1998
# Whom:					SADA Kenji <sada@e-mail.ne.jp>
#
# $Id$
#

DISTNAME=	ja-p5-jcode.pl-2.6
CATEGORIES=	japanese perl5
DISTFILES=

MAINTAINER=	sada@e-mail.ne.jp

RUN_DEPENDS=	${PREFIX}/lib/perl/jcode.pl:${PORTSDIR}/japanese/jcode.pl

NO_BUILD=	YES
USE_PERL5=	YES

LN=		/bin/ln

do-install:
	@${MKDIR} ${PREFIX}/lib/perl5/site_perl
	@${LN} -s ../../perl/jcode.pl ${PREFIX}/lib/perl5/site_perl

.include <bsd.port.mk>
