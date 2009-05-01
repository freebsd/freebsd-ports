# New ports collection makefile for:	p5-HTML-MobileJp
# Date created:		2009-04-19
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	HTML-MobileJp
PORTVERSION=	0.05
CATEGORIES=	japanese www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Generate mobile-jp html tags

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::MobileJp.3 \
		HTML::MobileJp::Plugin::GPS.3 \
		HTML::MobileJp::Plugin::EZweb::Object.3

.include <bsd.port.mk>
