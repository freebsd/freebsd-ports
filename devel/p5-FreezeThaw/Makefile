# New ports collection makefile for:    p5-FreezeThaw
# Version required:			0.3
# Date created:				September 10th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.2 1998/05/14 08:15:36 vanilla Exp $
#

DISTNAME=	FreezeThaw-0.3
PKGNAME=	p5-FreezeThaw-0.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	FreezeThaw

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		FreezeThaw.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
