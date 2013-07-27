# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-MySQLSequence
PORTVERSION=	1.04
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Proper and correct (emulated) sequence support for MySQL

BUILD_DEPENDS=	p5-DBD-mysql>0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
		p5-Params-Util>=0.26:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS=	p5-DBD-mysql>0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
		p5-Params-Util>=0.26:${PORTSDIR}/devel/p5-Params-Util

PERL_CONFIGURE=	yes

MAN3=	DBIx::MySQLSequence.3

post-patch:
	@${REINPLACE_CMD} -i '' '/Test::More/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
