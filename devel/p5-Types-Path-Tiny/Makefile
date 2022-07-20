PORTNAME=	Types-Path-Tiny
PORTVERSION=	0.006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Path::Tiny types and coercions for Moose and Moo

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Type-Tiny>=0.008:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-File-pushd>=0:devel/p5-File-pushd

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
