# New ports collection makefile for:    p5-Proc-Simple
# Version required:			1.12
# Date created:				June 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.ORG>
#
#   $Id: Makefile,v 1.1.1.1 1997/06/27 01:52:15 jfitz Exp $
#

DISTNAME=	Proc-Simple-1.12
PKGNAME=	p5-Proc-Simple-1.12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Proc

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Proc::Simple.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
