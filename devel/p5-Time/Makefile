# New ports collection makefile for:	p5-Time-961002
# Version required:			97.092101
# Date created:				October 12th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.8 1998/03/11 03:05:06 vanilla Exp $
#

DISTNAME=	Time-modules-97.092101
PKGNAME=	p5-Time-970921
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Time

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		Time::CTime.3 Time::JulianDay.3 Time::ParseDate.3 \
		Time::Timezone.3 Time::DaysInMonth.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
