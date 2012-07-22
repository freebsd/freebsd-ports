# New ports collection makefile for:	p5-Test-MockObject
# Date Created:				16 Jul, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-MockObject
PORTVERSION=	1.20120301
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Tests remote URLs or local web files

BUILD_DEPENDS=	p5-UNIVERSAL-can>=1.20110617:${PORTSDIR}/devel/p5-UNIVERSAL-can \
		p5-UNIVERSAL-isa>=1.20110614:${PORTSDIR}/devel/p5-UNIVERSAL-isa
RUN_DEPENDS=	p5-UNIVERSAL-can>=1.20110617:${PORTSDIR}/devel/p5-UNIVERSAL-can \
		p5-UNIVERSAL-isa>=1.20110614:${PORTSDIR}/devel/p5-UNIVERSAL-isa
TEST_DEPENDS=	p5-Test-Exception>=0.31:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Warn>=0.23:${PORTSDIR}/devel/p5-Test-Warn

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		Test::MockObject.3 Test::MockObject::Extends.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
