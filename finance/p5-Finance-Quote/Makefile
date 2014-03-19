# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Finance-Quote
PORTVERSION=	1.28
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Get stock and mutual fund quotes from various exchanges

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-HTML-TableExtract>=0:${PORTSDIR}/www/p5-HTML-TableExtract \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Mozilla-CA>=0:${PORTSDIR}/www/p5-Mozilla-CA \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Kwalitee>=0:${PORTSDIR}/devel/p5-Test-Kwalitee \
		p5-Test-Perl-Critic>=0:${PORTSDIR}/textproc/p5-Test-Perl-Critic

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
