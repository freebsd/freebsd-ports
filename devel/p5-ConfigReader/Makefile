# New ports collection makefile for:	p5-ConfigReader
# Version required:			0.5
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1996/10/24 07:56:23 jfitz Exp $
#

DISTNAME=	ConfigReader-0.5
PKGNAME=	p5-ConfigReader-0.5
CATEGORIES+=	devel
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/ConfigReader/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/ConfigReader/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/ConfigReader/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/ConfigReader/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/ConfigReader/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/ConfigReader/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

NO_BUILD=	YES

do-install:
		@ ${MKDIR} -p ${PREFIX}/lib/perl5/site_perl/ConfigReader/
		@ ${INSTALL_DATA} ${WRKSRC}/DirectiveStyle.pm ${PREFIX}/lib/perl5/site_perl/ConfigReader/
		@ ${INSTALL_DATA} ${WRKSRC}/Spec.pm ${PREFIX}/lib/perl5/site_perl/ConfigReader/
		@ ${INSTALL_DATA} ${WRKSRC}/Values.pm ${PREFIX}/lib/perl5/site_perl/ConfigReader/
		@ ${INSTALL_DATA} ${WRKSRC}/ConfigReader.pod ${PREFIX}/lib/perl5/site_perl/

.include <bsd.port.mk>
