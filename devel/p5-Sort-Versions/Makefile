# New ports collection makefile for:    p5-Sort-Versions
# Version required:			1.1
# Date created:				June 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.ORG>
#
#   $Id: Makefile,v 1.1.1.1 1997/06/27 01:54:30 jfitz Exp $
#

DISTNAME=	SortVersions-1.1
PKGNAME=	p5-Sort-Versions-1.1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Sort

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Sort::Versions.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
