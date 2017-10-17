# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBICx-MapMaker
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JROCKWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl 5 module to automatically create a DBIx::Class mapping table

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Moose>=0.39:devel/p5-Moose
BUILD_DEPENDS=	p5-DBIx-Class>=0.07003:databases/p5-DBIx-Class \
		p5-DBICx-TestDatabase>=0.02:databases/p5-DBICx-TestDatabase \
		p5-Moose>=0.39:devel/p5-Moose

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
