# New ports collection makefile for:	p5-Devel-DProf
# Version required:			19970614
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.5 1998/09/15 21:31:35 asami Exp $
#

DISTNAME=	DProf-19970614
PKGNAME=	p5-Devel-DProf-19970614
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

OSVERSION!=     sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=         perl
.endif

MAN1PREFIX=	${PREFIX}
MAN1=		dprofpp.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Devel::DProf.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
