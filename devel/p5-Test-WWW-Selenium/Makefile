# New ports collection makefile for:	devel/p5-Test-WWW-Selenium
# Date created:				12 June, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Test-WWW-Selenium
PORTVERSION=	1.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Perl driver and test library for Selenium Remote Control (SRC)

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Mock-LWP>=0:${PORTSDIR}/devel/p5-Test-Mock-LWP \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::WWW::Selenium.3 \
	WWW::Selenium::Util.3 \
	WWW::Selenium.3

.include <bsd.port.mk>
