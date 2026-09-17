PORTNAME=	Mojo-SQLite
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0
CATEGORIES=	databases www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DBOOK
PKGNAMEPREFIX=	p5-

MAINTAINER=	simeo.reig@gmail.com
COMMENT=	Tiny Mojolicious wrapper for SQLite
WWW=		https://metacpan.org/pod/Mojo::SQLite \
		https://github.com/Grinnz/Mojo-SQLite

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_RUN_DEPENDS=	p5-DBD-SQLite>=1.68:databases/p5-DBD-SQLite \
			p5-DBI>=1.627:databases/p5-DBI \
			p5-Mojolicious>=8.03:www/p5-Mojolicious \
			p5-SQL-Abstract-Pg>=1.0:databases/p5-SQL-Abstract-Pg \
			p5-URI-db>=0.15:net/p5-URI-db \
			p5-URI>=1.69:net/p5-URI

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
