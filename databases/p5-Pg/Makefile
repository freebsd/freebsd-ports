# New ports collection makefile for:	p5-Pg
# Version required:			1.2.0
# Date created:				October 19th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id$
#

DISTNAME=	pg95perl5-1.2.0
PKGNAME=	p5-Pg-1.2.0
CATEGORIES+=	databases
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Pg/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Pg/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Pg/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Pg/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Pg/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Pg/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		${PREFIX}/postgres95/lib/libpq.a:${PORTSDIR}/databases/postgres95

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
