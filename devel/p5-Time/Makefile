# New ports collection makefile for:	p5-Time-961002
# Version required:			97.011701
# Date created:				October 12th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.5 1997/04/20 21:26:23 jfitz Exp $
#

DISTNAME=	Time-modules-97.011701
PKGNAME=	p5-Time-960117
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Time

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.004:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5

MAN3=		Time::CTime.3 Time::JulianDay.3 Time::ParseDate.3 \
		Time::Timezone.3 Time::DaysInMonth.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
