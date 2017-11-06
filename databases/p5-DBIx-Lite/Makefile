# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Lite
PORTVERSION=	0.31
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Chained and minimal ORM

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBIx-Connector>=0:databases/p5-DBIx-Connector \
		p5-Data-Page>=0:databases/p5-Data-Page \
		p5-SQL-Abstract-More>=0:databases/p5-SQL-Abstract-More
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=1.29:databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
