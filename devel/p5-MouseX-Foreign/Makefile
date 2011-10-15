# New ports collection makefile for:	p5-MouseX-Foreign
# Date created:		2011-08-15
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MouseX-Foreign
PORTVERSION=	0.006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extends non-Mouse classes as well as Mouse classes

BUILD_DEPENDS=	p5-Mouse>=0.77:${PORTSDIR}/devel/p5-Mouse
RUN_DEPENDS=	p5-Mouse>=0.77:${PORTSDIR}/devel/p5-Mouse

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

PERL_CONFIGURE=	yes

MAN3=		MouseX::Foreign.3 \
		MouseX::Foreign::Meta::Role::Class.3 \
		MouseX::Foreign::Meta::Role::Method::Constructor.3 \
		MouseX::Foreign::Meta::Role::Method::Destructor.3 \
		MouseX::NonMoose.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
