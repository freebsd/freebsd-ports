# New ports collection makefile for:	p5-Religion
# Version required:			1.04
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.6 1997/06/24 18:43:30 jfitz Exp $
#

DISTNAME=	Religion-1.04
PKGNAME=	p5-Religion-1.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Religion

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		Religion.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
