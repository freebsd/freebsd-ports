# New ports collection makefile for:	p5-Devel-Symdump
# Version required:			2.00
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.2 1997/06/24 18:43:17 jfitz Exp $
#

DISTNAME=	Devel-Symdump-2.00
PKGNAME=	p5-Devel-Symdump-2.00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/5.00501
MAN3=		Devel::Symdump.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
