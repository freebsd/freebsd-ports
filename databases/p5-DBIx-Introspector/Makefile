# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Introspector
PORTVERSION=	0.001005
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Detect what database you are connected to

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-Moo>=0:devel/p5-Moo

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
