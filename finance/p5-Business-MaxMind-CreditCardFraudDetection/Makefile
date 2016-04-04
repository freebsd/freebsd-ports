# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	Business-MaxMind-CreditCardFraudDetection
PORTVERSION=	1.57
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MAXMIND
PKGNAMEPREFIX=	p5-
DISTNAME=	Business-MaxMind-${PORTVERSION}

MAINTAINER=	vivek@khera.org
COMMENT=	Interface to MaxMind minFraud service

RUN_DEPENDS+=	p5-libwww>0.0:www/p5-libwww \
		p5-LWP-Protocol-https>0.0:www/p5-LWP-Protocol-https
BUILD_DEPENDS+=	p5-libwww>0.0:www/p5-libwww

USES=		perl5 shebangfix
SHEBANG_FILES=	example*.pl
USE_PERL5=	configure
NO_ARCH=	yes

PLIST_FILES=	\
	%%SITE_PERL%%/Business/MaxMind.pm \
	%%SITE_PERL%%/Business/MaxMind/CreditCardFraudDetection.pm \
	%%SITE_PERL%%/Business/MaxMind/HTTPBase.pm \
	%%SITE_PERL%%/Business/MaxMind/TelephoneVerification.pm \
	%%SITE_PERL%%/Business/example.pl \
	%%SITE_PERL%%/Business/example_telv.pl \
	%%PERL5_MAN3%%/Business::MaxMind.3.gz \
	%%PERL5_MAN3%%/Business::MaxMind::CreditCardFraudDetection.3.gz \
	%%PERL5_MAN3%%/Business::MaxMind::HTTPBase.3.gz \
	%%PERL5_MAN3%%/Business::MaxMind::TelephoneVerification.3.gz

.include <bsd.port.mk>
