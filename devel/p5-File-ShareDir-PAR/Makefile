# New ports collection makefile for:	p5-File-ShareDir-PAR
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	File-ShareDir-PAR
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl5 File::ShareDir module with PAR support

BUILD_DEPENDS=	${SITE_PERL}/Class/Inspector.pm:${PORTSDIR}/devel/p5-Class-Inspector \
		${SITE_PERL}/File/ShareDir.pm:${PORTSDIR}/devel/p5-File-ShareDir \
		${SITE_PERL}/PAR.pm:${PORTSDIR}/devel/p5-PAR \
		${SITE_PERL}/${PERL_ARCH}/Params/Util.pm:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		File::ShareDir::PAR.3

.include <bsd.port.mk>
