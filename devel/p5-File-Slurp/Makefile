# New ports collection makefile for:	p5-File-Slurp
# Version required:			96.042202
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.6 1997/06/24 18:43:18 jfitz Exp $
#

DISTNAME=	File-Slurp-96.042202
PKGNAME=	p5-File-Slurp-96.042202
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		File::Slurp.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
