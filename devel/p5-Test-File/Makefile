# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-File
PORTVERSION=	1.42
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test file attributes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-utf8>=0:${PORTSDIR}/devel/p5-Test-utf8

USES=		perl5
USE_PERL5=	configure

post-install:
	${FIND} ${STAGEDIR} \( -name README.pod -o -name Test::README.3 \) -delete

.include <bsd.port.mk>
