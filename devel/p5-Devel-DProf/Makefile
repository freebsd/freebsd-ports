# New ports collection makefile for:	p5-Devel-DProf
# Version required:			19990108
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.7 1998/11/11 05:37:11 asami Exp $
#

DISTNAME=	DProf-19990108
PKGNAME=	p5-Devel-DProf-19990108
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel

MAINTAINER=	jfitz@FreeBSD.ORG

CONFIGURE_ARGS=	PREFIX=${PREFIX}
USE_PERL5=	YES

MAN1PREFIX=	${PREFIX}
MAN1=		dprofpp.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Devel::DProf.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${CONFIGURE_ARGS}

.include <bsd.port.mk>
