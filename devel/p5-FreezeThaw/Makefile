# New ports collection makefile for:    p5-FreezeThaw
# Version required:			0.3
# Date created:				September 10th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.1.1.1 1997/09/13 17:44:00 jfitz Exp $
#

DISTNAME=	FreezeThaw-0.3
PKGNAME=	p5-FreezeThaw-0.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	FreezeThaw

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		FreezeThaw.3
MAN3PREFIX=	${PREFIX}/lib/perl5

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
