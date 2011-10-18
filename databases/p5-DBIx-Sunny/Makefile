# New ports collection makefile for:	DBIx::Sunny
# Date created:				18 October 2011
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Sunny
PORTVERSION=	0.14
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A simple DBI wrapper supports SQLite and MySQL

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=1.615:${PORTSDIR}/databases/p5-DBI \
    		p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Class-Accessor-Lite>=0.05:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-DBIx-TransactionManager>=0:${PORTSDIR}/databases/p5-DBIx-TransactionManager \
		p5-Data-Validator>=0:${PORTSDIR}/devel/p5-Data-Validator
RUN_DEPENDS=	p5-DBI>=1.615:${PORTSDIR}/databases/p5-DBI \
		p5-Class-Accessor-Lite>=0.05:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-DBIx-TransactionManager>=0:${PORTSDIR}/databases/p5-DBIx-TransactionManager \
		p5-Data-Validator>=0:${PORTSDIR}/devel/p5-Data-Validator

TEST_DEPENDS=	p5-DBD-SQLite>=1.27:${PORTSDIR}/databases/p5-DBD-SQLite \
    		p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny

PERL_CONFIGURE=	yes

MAN3=	DBIx::Sunny.3 \
	DBIx::Sunny::Schema.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001

BUILD_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
RUN_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>
