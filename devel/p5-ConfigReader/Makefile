# New ports collection makefile for:	p5-ConfigReader
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ConfigReader
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	ConfigReader
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module to read directives from a configuration file

USE_PERL5=	YES

NO_BUILD=	YES

do-install:
		@ ${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/ConfigReader/
		@ ${INSTALL_DATA} ${WRKSRC}/DirectiveStyle.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/ConfigReader/
		@ ${INSTALL_DATA} ${WRKSRC}/Spec.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/ConfigReader/
		@ ${INSTALL_DATA} ${WRKSRC}/Values.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/ConfigReader/
		@ ${INSTALL_DATA} ${WRKSRC}/ConfigReader.pod ${PREFIX}/lib/perl5/site_perl/${PERL_VER}

.include <bsd.port.mk>
