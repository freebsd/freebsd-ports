# New ports collection makefile for:	p5-Time-961002
# Version required:			96.100201
# Date created:				October 12th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/24 09:59:30 jfitz Exp $
#

DISTNAME=	Time-modules-96.100201
PKGNAME=	p5-Time-961002
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Time

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN3=		Time::CTime.3 Time::JulianDay.3 Time::ParseDate.3 \
		Time::Timezone.3 Time::DaysInMonth.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
