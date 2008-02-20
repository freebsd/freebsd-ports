# New ports collection makefile for:	p5-SMS-Send
# Date created:		2006-08-26
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	SMS-Send
PORTVERSION=	0.05
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Driver-based API for sending SMS messages

BUILD_DEPENDS=	${SITE_PERL}/Class/Adapter.pm:${PORTSDIR}/devel/p5-Class-Adapter \
		${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable \
		${SITE_PERL}/Params/Util.pm:${PORTSDIR}/devel/p5-Params-Util \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SMS::Send.3 \
		SMS::Send::AU::Test.3 \
		SMS::Send::Driver.3 \
		SMS::Send::Test.3

.include <bsd.port.mk>
