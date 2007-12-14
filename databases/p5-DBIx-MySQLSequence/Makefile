# New ports collection makefile for:	databases/p5-DBIx-MySQLSequence
# Date created:				18 March 2006
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-MySQLSequence
PORTVERSION=	1.04
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Proper and correct (emulated) sequence support for MySQL

RUN_DEPENDS=	p5-DBD-mysql>0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
		p5-Params-Util>=0.26:${PORTSDIR}/devel/p5-Params-Util
BUILD_DEPENDS=	${RUN}

PERL_CONFIGURE=	yes

MAN3=	DBIx::MySQLSequence.3

post-patch:
	@${PERL} -pi -e '$$_="" if m/Test::More/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
