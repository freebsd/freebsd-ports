# New ports collection makefile for:	p5-Devel-DProf
# Version required:			19970614
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1997/06/17 22:48:05 jfitz Exp $
#

DISTNAME=	DProf-19970614
PKGNAME=	p5-Devel-DProf-19970614
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN1PREFIX=	${PREFIX}
MAN1=		dprofpp.1
MAN3PREFIX=	${PREFIX}/lib/perl5
MAN3=		Devel::DProf.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
