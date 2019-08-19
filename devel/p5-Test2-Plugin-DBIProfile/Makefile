# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test2-Plugin-DBIProfile
PORTVERSION=	0.002001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Plugin to enable and display DBI profiling

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	configure

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Test-Simple>=1.302165:devel/p5-Test-Simple
TEST_DEPENDS=	p5-DBD-SQLite>=1.44:databases/p5-DBD-SQLite \
		p5-Test2-Suite>=0.000124:devel/p5-Test2-Suite

NO_ARCH=	yes

.include <bsd.port.mk>
