# New ports collection makefile for:	p5-DBI
# Version required:			0.73
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1996/10/23 23:52:52 jfitz Exp $
#

DISTNAME=	DBI-0.73
PKGNAME=	p5-DBI-0.73
CATEGORIES+=	databases
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/DBI/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/DBI/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/DBI/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/DBI/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/DBI/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/DBI/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
