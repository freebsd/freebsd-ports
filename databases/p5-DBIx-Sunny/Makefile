# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Sunny
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple DBI wrapper supports SQLite and MySQL

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=1.615:${PORTSDIR}/databases/p5-DBI \
		p5-Class-Accessor-Lite>=0.05:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-DBIx-TransactionManager>=0:${PORTSDIR}/databases/p5-DBIx-TransactionManager \
		p5-Data-Validator>=0:${PORTSDIR}/devel/p5-Data-Validator
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=1.31:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
    		p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
