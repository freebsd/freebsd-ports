# New ports collection makefile for:	p5-Resources
# Version required:			1.04
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.7 1997/06/24 18:43:31 jfitz Exp $
#

DISTNAME=	Resources-1.04
PKGNAME=	p5-Resources-1.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Resources

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		Resources.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
