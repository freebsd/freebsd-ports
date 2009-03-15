# New ports collection makefile for:	p5-Module-Math-Depends
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Module-Math-Depends
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Convenience object for manipulating module dependencies

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Params/Util.pm:${PORTSDIR}/devel/p5-Params-Util \
		${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Module::Math::Depends.3

.include <bsd.port.mk>
