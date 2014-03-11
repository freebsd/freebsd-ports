# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Admin-CreateTable
PORTVERSION=	2.10
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create and drop tables, primary indexes, and sequences

LICENSE=	ART20

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Moo>=1.004002:${PORTSDIR}/devel/p5-Moo
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Version>=1.002.003:${PORTSDIR}/devel/p5-Test-Version

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
