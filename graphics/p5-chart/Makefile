# New ports collection makefile for:	p5-chart
# Version required:	0.94
# Date Created:		8 April 1998
# Whom:			Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/04/11 13:51:41 vanilla Exp $
#

DISTNAME=	chart-0.94
PKGNAME=	p5-chart-0.94
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Chart

MAINTAINER=	ports@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/5.005/i386-freebsd/GD.pm:${PORTSDIR}/graphics/p5-GD

WRKSRC=		${WRKDIR}/Chart-0.94

USE_PERL5=	YES

MAN3=		Chart.3
MANPREFIX=	${PREFIX}/lib/perl5/5.00501

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
