# New ports collection makefile for:	p5-Module-Manifest
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Module-Manifest
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Parse and examine a Perl distribution MANIFEST file

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Params/Util.pm:${PORTSDIR}/devel/p5-Params-Util \
		${SITE_PERL}/Test/Warn.pm:${PORTSDIR}/devel/p5-Test-Warn
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Module::Manifest.3

.include <bsd.port.mk>
