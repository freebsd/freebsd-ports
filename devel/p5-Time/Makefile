# New ports collection makefile for:	p5-Time-961002
# Version required:			96.100201
# Date created:				October 12th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id$
#

DISTNAME=	Time-modules-96.100201
PKGNAME=	p5-Time-961002
CATEGORIES+=	devel
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Time/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Time/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Time/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Time/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Time/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Time/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in Time::CTime Time::JulianDay Time::ParseDate Time::Timezone Time::DaysInMonth; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
.endif

.include <bsd.port.mk>
