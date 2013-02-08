# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Carp-Always-Color
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Carp::Always, but with color

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Carp-Always>=0.10:${PORTSDIR}/devel/p5-Carp-Always
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-Pty-Easy>=0:${PORTSDIR}/devel/p5-IO-Pty-Easy

PERL_CONFIGURE=	yes

MAN3=		Carp::Always::Color.3 \
		Carp::Always::Color::HTML.3 \
		Carp::Always::Color::Term.3

.include <bsd.port.mk>
