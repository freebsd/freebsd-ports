# ex:ts=8
# Ports collection makefile for:	Astro-ADS
# Date created:			Oct 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Astro-ADS
PORTVERSION=	1.20.7
CATEGORIES=	astro perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.estar.org.uk/software/
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OO Perl interface to the ADS abstract service

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN1=	adsquery.1
MAN3=	Astro::ADS.3 Astro::ADS::Query.3 Astro::ADS::Result.3 Astro::ADS::Result::Paper.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
post-patch:
	@${PERL} -pi -e 's/(\$$self->\$$method);/$$1();/' ${WRKSRC}/Result/Paper/Paper.pm
.endif

.include <bsd.port.post.mk>
