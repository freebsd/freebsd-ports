# New ports collection makefile for:	p5-ConfigReader
# Version required:			0.5
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	ConfigReader-0.5
PKGNAME=	p5-ConfigReader-0.5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	ConfigReader

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	YES

NO_BUILD=	YES

do-install:
		@ ${MKDIR} ${PREFIX}/lib/perl5/site_perl/ConfigReader/
		@ ${INSTALL_DATA} ${WRKSRC}/DirectiveStyle.pm ${PREFIX}/lib/perl5/site_perl/ConfigReader/
		@ ${INSTALL_DATA} ${WRKSRC}/Spec.pm ${PREFIX}/lib/perl5/site_perl/ConfigReader/
		@ ${INSTALL_DATA} ${WRKSRC}/Values.pm ${PREFIX}/lib/perl5/site_perl/ConfigReader/
		@ ${INSTALL_DATA} ${WRKSRC}/ConfigReader.pod ${PREFIX}/lib/perl5/site_perl/

.include <bsd.port.mk>
