# New ports collection makefile for:	p5-Method-Signatures-Simple
# Date created:		2010-10-08
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Method-Signatures-Simple
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/R/RH/RHESA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Basic method declarations with signatures, without source filters

PLIST_FILES=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Method/Signatures/Simple/.packlist \
		%%SITE_PERL%%/Method/Signatures/Simple.pm
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Method/Signatures/Simple \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Method/Signatures \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Method \
		%%SITE_PERL%%/Method/Signatures \
		%%SITE_PERL%%/Method

PERL_CONFIGURE=	YES

MAN3=	Method::Signatures::Simple.3

.include <bsd.port.mk>
