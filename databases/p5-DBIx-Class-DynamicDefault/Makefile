# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-DynamicDefault
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatically set and update fields

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBIx-Class>=0.08127:databases/p5-DBIx-Class
TEST_DEPENDS=	p5-DBICx-TestDatabase>=0:databases/p5-DBICx-TestDatabase

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
