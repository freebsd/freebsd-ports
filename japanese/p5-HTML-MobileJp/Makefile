# New ports collection makefile for:	p5-HTML-MobileJp
# Date created:		2009-04-19
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	HTML-MobileJp
PORTVERSION=	0.08
CATEGORIES=	japanese www perl5
MASTER_SITES=	CPAN

MAINTAINER=	markun@onohara.to
COMMENT=	Generate mobile-jp html tags

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Base>0:${PORTSDIR}/devel/p5-Test-Base \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

MAN3=		HTML::MobileJp.3 \
		HTML::MobileJp::Plugin::GPS.3 \
		HTML::MobileJp::Plugin::EZweb::Object.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
