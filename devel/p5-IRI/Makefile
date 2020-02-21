# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IRI
PORTVERSION=	0.011
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GWILLIAMS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Internationalized Resource Identifiers

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moo>=0:devel/p5-Moo \
		p5-MooX-HandlesVia>=0:devel/p5-MooX-HandlesVia \
		p5-Type-Tiny>=0.008:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

.include <bsd.port.mk>
