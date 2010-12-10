# New ports collection makefile for:	p5-Net-IDN-Nameprep
# Date created:				10 Dec 2010
# Whom:					Timur Bakeyev <bat@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Net-IDN-Nameprep
PORTVERSION=	1.100
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	timur@FreeBSD.org
COMMENT=	normalization of domain names (Nameprep, RFC 3491)

RUN_DEPENDS=	${SITE_PERL}/Unicode/Stringprep.pm:${PORTSDIR}/converters/p5-Unicode-Stringprep
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/NoWarnings.pm:${PORTSDIR}/devel/p5-Test-NoWarnings

PERL_MODBUILD=	yes

MAN3=		Net::IDN::Nameprep.3

.include <bsd.port.mk>
