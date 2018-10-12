# Created by: Nick Hibma <n_hibma@freebsd.org>
# $FreeBSD$

PORTNAME=	Mongoose
PORTVERSION=	2.00
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DIEGOK
PKGNAMEPREFIX=	p5-

MAINTAINER=	n_hibma@FreeBSD.org
COMMENT=	MongoDB document to Moose object mapper

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-MongoDB>=0:databases/p5-MongoDB \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Singleton>=0:devel/p5-MooseX-Singleton \
		p5-MooseX-Role-Parameterized>=0:devel/p5-MooseX-Role-Parameterized \
		p5-Params-Coerce>=0:devel/p5-Params-Coerce

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
