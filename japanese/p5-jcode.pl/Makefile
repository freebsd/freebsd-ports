# New ports collection makefile for:	p5-jcode.pl
# Version required:			2.6
# Date created:				26 Jun 1998
# Whom:					SADA Kenji <sada@e-mail.ne.jp>
#
# $Id: Makefile,v 1.1.1.1 1998/08/12 14:04:13 kuriyama Exp $
#

DISTNAME=	ja-p5-jcode.pl-2.6
CATEGORIES=	japanese perl5
DISTFILES=

MAINTAINER=	sada@e-mail.ne.jp

RUN_DEPENDS=	${PREFIX}/lib/perl/jcode.pl:${PORTSDIR}/japanese/jcode.pl

NO_BUILD=	YES
USE_PERL5=	YES

do-install:
	@${MKDIR} ${PREFIX}/lib/perl5/site_perl
	@${LN} -sf ../../perl/jcode.pl ${PREFIX}/lib/perl5/site_perl

.include <bsd.port.mk>
