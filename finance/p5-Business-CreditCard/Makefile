# New ports collection makefile for:	p5-Business-CreditCard
# Version required:			0.21
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Business-CreditCard-0.21
PKGNAME=	p5-Business-CreditCard-0.21
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Business

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	YES

NO_BUILD=	YES

do-install:
		@ ${CP} ${WRKSRC}/CreditCard.pm ${WRKSRC}/CreditCard-0.21.pm
		@ ${MKDIR} ${PREFIX}/lib/perl5/site_perl/Business/
		@ ${INSTALL_DATA} ${WRKSRC}/CreditCard-0.21.pm ${PREFIX}/lib/perl5/site_perl/Business/
		@ ${LN} -sf ${PREFIX}/lib/perl5/site_perl/Business/CreditCard-0.21.pm ${PREFIX}/lib/perl5/site_perl/Business/CreditCard.pm

.include <bsd.port.mk>
