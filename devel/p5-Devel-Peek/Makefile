# New ports collection makefile for:	p5-Devel-Peek
# Version required:			0.94
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.6 1998/06/24 15:53:11 vanilla Exp $
#

DISTNAME=	Devel-Peek-0.94
PKGNAME=	p5-Devel-Peek-0.94
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/5.00501
MAN3=		Devel::Peek.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
