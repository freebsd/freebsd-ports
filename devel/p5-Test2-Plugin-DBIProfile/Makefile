# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	Test2-Plugin-DBIProfile
PORTVERSION=	0.002003
PORTREVISION=	1
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
RUN_DEPENDS=	p5-Test2-Suite>=0.000126:devel/p5-Test2-Suite
TEST_DEPENDS=	p5-DBD-SQLite>=1.44:databases/p5-DBD-SQLite

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 503200
RUN_DEPENDS+=	p5-Test-Simple>=1.302165:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
