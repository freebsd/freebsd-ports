# New ports collection makefile for:	p5-Business-CreditCard
# Version required:			0.1
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id$
#

DISTNAME=	Business-CreditCard-0.1
PKGNAME=	p5-Business-CreditCard-0.1
CATEGORIES+=	misc
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Business/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Business/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Business/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Business/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Business/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Business/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5

NO_BUILD=	YES

do-install:
		@ ${CP} ${WRKSRC}/CreditCard.pm ${WRKSRC}/CreditCard-0.1.pm
		@ ${MKDIR} -p ${PREFIX}/lib/perl5/site_perl/Business/
		@ ${INSTALL_DATA} ${WRKSRC}/CreditCard-0.1.pm ${PREFIX}/lib/perl5/site_perl/Business/
		@ ln -sf ${PREFIX}/lib/perl5/site_perl/Business/CreditCard-0.1.pm ${PREFIX}/lib/perl5/site_perl/Business/CreditCard.pm

.include <bsd.port.mk>
