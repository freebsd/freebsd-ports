# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	Business-MaxMind-CreditCardFraudDetection
PORTVERSION=	1.54
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BORISZ
PKGNAMEPREFIX=	p5-
DISTNAME=	Business-MaxMind-${PORTVERSION}

MAINTAINER=	vivek@khera.org
COMMENT=	Interface to MaxMind minFraud service

RUN_DEPENDS+=	p5-libwww>0.0:${PORTSDIR}/www/p5-libwww \
		p5-Crypt-SSLeay>0.0:${PORTSDIR}/security/p5-Crypt-SSLeay
BUILD_DEPENDS+=	p5-libwww>0.0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

MAN3=	Business::MaxMind::CreditCardFraudDetection.3 \
	Business::MaxMind::HTTPBase.3 \
	Business::MaxMind::TelephoneVerification.3 \

PLIST_FILES=	\
	%%SITE_PERL%%/Business/MaxMind/CreditCardFraudDetection.pm \
	%%SITE_PERL%%/Business/MaxMind/HTTPBase.pm \
	%%SITE_PERL%%/Business/MaxMind/TelephoneVerification.pm \
	%%SITE_PERL%%/Business/example.pl \
	%%SITE_PERL%%/Business/example_telv.pl \
	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Business/MaxMind/.packlist

PLIST_DIRS=	\
	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Business/MaxMind \
	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Business \
	%%SITE_PERL%%/Business/MaxMind \
	%%SITE_PERL%%/Business

NO_STAGE=	yes
.include <bsd.port.mk>
