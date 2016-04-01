# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-MySQLSequence
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Proper and correct (emulated) sequence support for MySQL

BUILD_DEPENDS=	p5-DBD-mysql>0:databases/p5-DBD-mysql \
		p5-DBI>0:databases/p5-DBI \
		p5-Params-Util>=0.26:devel/p5-Params-Util
RUN_DEPENDS=	p5-DBD-mysql>0:databases/p5-DBD-mysql \
		p5-DBI>0:databases/p5-DBI \
		p5-Params-Util>=0.26:devel/p5-Params-Util

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -i '' '/Test::More/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
