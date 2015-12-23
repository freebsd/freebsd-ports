# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Cpanel-JSON-XS
PORTVERSION=	3.0210
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RURBAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON::XS for Cpanel, fast and correct serialising

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-Mojolicious>=6.11:${PORTSDIR}/www/p5-Mojolicious \
		p5-Perl-MinimumVersion>=1.20:${PORTSDIR}/textproc/p5-Perl-MinimumVersion \
		p5-Test-CPAN-Meta>=1.20:${PORTSDIR}/devel/p5-Test-CPAN-Meta \
		p5-Test-LeakTrace>=0:${PORTSDIR}/devel/p5-Test-LeakTrace \
		p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-common-sense>=3.50:${PORTSDIR}/devel/p5-common-sense

USE_PERL5=	configure
USES=		perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Cpanel/JSON/XS/XS.so

.include <bsd.port.mk>
