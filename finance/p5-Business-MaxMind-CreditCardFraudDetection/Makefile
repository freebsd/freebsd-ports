# New ports collection makefile for:	p5-Business-MaxMind-CreditCardFraudDetection
# Date created:				Thu Jan 10 16:13:05 EST 2008
# Whom:					Vivek Khera <vivek@khera.org>
#
# $FreeBSD$
#

PORTNAME=	Business-MaxMind-CreditCardFraudDetection
PORTVERSION=	1.50
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/B/BO/BORISZ
PKGNAMEPREFIX=	p5-
DISTNAME=	Business-MaxMind-${PORTVERSION}

MAINTAINER=	vivek@khera.org
COMMENT=	Interface to MaxMind minFraud service

RUN_DEPENDS+=	p5-libwww>0.0:${PORTSDIR}/www/p5-libwww \
		p5-Crypt-SSLeay>0.0:${PORTSDIR}/security/p5-Crypt-SSLeay
BUILD_DEPENDS+=	p5-libwww>0.0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=	Business::MaxMind::CreditCardFraudDetection.3 \
	Business::MaxMind::HTTPBase.3 \
	Business::MaxMind::LocationVerification.3 \
	Business::MaxMind::TelephoneVerification.3 \

PLIST_FILES=	\
	%%SITE_PERL%%/Business/MaxMind/CreditCardFraudDetection.pm \
	%%SITE_PERL%%/Business/MaxMind/HTTPBase.pm \
	%%SITE_PERL%%/Business/MaxMind/LocationVerification.pm \
	%%SITE_PERL%%/Business/MaxMind/TelephoneVerification.pm \
	%%SITE_PERL%%/Business/example.pl \
	%%SITE_PERL%%/Business/example_locv.pl \
	%%SITE_PERL%%/Business/example_telv.pl \
	%%SITE_PERL%%/auto/Business/MaxMind/HTTPBase/autosplit.ix \
	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Business/MaxMind/.packlist

PLIST_DIRS=	\
	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Business/MaxMind \
	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Business \
	%%SITE_PERL%%/auto/Business/MaxMind/HTTPBase \
	%%SITE_PERL%%/auto/Business/MaxMind \
	%%SITE_PERL%%/auto/Business \
	%%SITE_PERL%%/Business/MaxMind \
	%%SITE_PERL%%/Business \

.include <bsd.port.mk>
