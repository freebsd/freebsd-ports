PORTNAME=	Minion
PORTVERSION=	11.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Asynchronous job queue for Mojolicious
WWW=		https://metacpan.org/release/Minion

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Mojolicious>=9.0:www/p5-Mojolicious \
		p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	PGSQL

PGSQL_BUILD_DEPENDS=	p5-Mojo-Pg>=4.0:databases/p5-Mojo-Pg
PGSQL_RUN_DEPENDS=	p5-Mojo-Pg>=4.0:databases/p5-Mojo-Pg

.include <bsd.port.mk>
