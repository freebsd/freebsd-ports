# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Admin-TableInfo
PORTVERSION=	2.11
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper for all of table_info(), column_info(), *_key_info()

LICENSE=	ART20

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-DBIx-Admin-CreateTable>=2.09:${PORTSDIR}/databases/p5-DBIx-Admin-CreateTable \
		p5-DBIx-Admin-DSNManager>=2:${PORTSDIR}/databases/p5-DBIx-Admin-DSNManager \
		p5-Data-Dumper-Concise>=2.021:${PORTSDIR}/devel/p5-Data-Dumper-Concise \
		p5-Moo>=1.004002:${PORTSDIR}/devel/p5-Moo
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Version>=1.002.003:${PORTSDIR}/devel/p5-Test-Version

USE_PERL5=	configure
USES=		perl5 tar:tgz

.include <bsd.port.mk>
