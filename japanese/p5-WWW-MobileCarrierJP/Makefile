# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	WWW-MobileCarrierJP
PORTVERSION=	0.63
CATEGORIES=	japanese www perl5
MASTER_SITES=	CPAN

MAINTAINER=	markun@onohara.to
COMMENT=	Scrape Japanese mobile carrier information

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Moose>=0.60:${PORTSDIR}/devel/p5-Moose \
		p5-Filter>=0:${PORTSDIR}/devel/p5-Filter \
		p5-HTML-Selector-XPath>=0.03:${PORTSDIR}/www/p5-HTML-Selector-XPath \
		p5-HTML-TableExtract>=2.10:${PORTSDIR}/www/p5-HTML-TableExtract \
		p5-Web-Scraper>=0.24:${PORTSDIR}/www/p5-Web-Scraper \
		p5-libwww>=5.834:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-parent>=0:${PORTSDIR}/devel/p5-parent \
		p5-CAM-PDF>=0:${PORTSDIR}/textproc/p5-CAM-PDF
BUILD_DEPENDS:=	${RUN_DEPENDS}

TEST_DEPENDS=	p5-LWP-Online>=1.07:${PORTSDIR}/www/p5-LWP-Online \
		p5-Test-Base>0:${PORTSDIR}/devel/p5-Test-Base

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
