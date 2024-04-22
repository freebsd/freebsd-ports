PORTNAME=	DBIx-MySQLSequence
PORTVERSION=	1.04
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Proper and correct (emulated) sequence support for MySQL
WWW=		https://metacpan.org/release/DBIx-MySQLSequence

BUILD_DEPENDS=	${DBD_MYSQL} \
		p5-DBI>0:databases/p5-DBI \
		p5-Params-Util>=0.26:devel/p5-Params-Util
RUN_DEPENDS=	${DBD_MYSQL} \
		p5-DBI>0:databases/p5-DBI \
		p5-Params-Util>=0.26:devel/p5-Params-Util

USES=		mysql perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -i '' '/Test::More/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
