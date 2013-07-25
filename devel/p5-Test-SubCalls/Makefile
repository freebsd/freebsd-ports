# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-SubCalls
PORTVERSION=	1.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Track the number of times subs are called

BUILD_DEPENDS=	p5-Hook-LexWrap>=0:${PORTSDIR}/devel/p5-Hook-LexWrap \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::SubCalls.3

.include <bsd.port.mk>
