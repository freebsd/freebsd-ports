# $FreeBSD$

PORTNAME=	DBIx-Class-InflateColumn-Authen-Passphrase
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fw@moov.de
COMMENT=	Inflate/deflate columns to Authen::Passphrase instances

RUN_DEPENDS=	p5-DBIx-Class-DynamicDefault>=0.03:databases/p5-DBIx-Class-DynamicDefault \
		p5-DBIx-Class>=0.08009:databases/p5-DBIx-Class \
		p5-Authen-Passphrase>=0:security/p5-Authen-Passphrase
BUILD_DEPENDS:=	p5-DBIx-Class-DynamicDefault>=0.03:databases/p5-DBIx-Class-DynamicDefault \
		p5-DBIx-Class>=0.08009:databases/p5-DBIx-Class \
		p5-Authen-Passphrase>=0:security/p5-Authen-Passphrase

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
