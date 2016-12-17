# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Admin-TableInfo
PORTVERSION=	3.03
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper for all of table_info(), column_info(), *_key_info()

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-DBIx-Admin-CreateTable>=2.10:databases/p5-DBIx-Admin-CreateTable \
		p5-DBIx-Admin-DSNManager>=2.01:databases/p5-DBIx-Admin-DSNManager \
		p5-Data-Dumper-Concise>=2.022:devel/p5-Data-Dumper-Concise \
		p5-Lingua-EN-PluralToSingular>=0.18:textproc/p5-Lingua-EN-PluralToSingular \
		p5-Moo>=2.002004:devel/p5-Moo \
		p5-Text-Table-Manifold>=1:textproc/p5-Text-Table-Manifold
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5 tar:tgz

.include <bsd.port.mk>
