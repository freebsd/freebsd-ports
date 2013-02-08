# Created by Frank Wall <fw@moov.de>
# $FreeBSD$

PORTNAME=	DBIx-Class-InflateColumn-Authen-Passphrase
PORTVERSION=	0.01
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	fw@moov.de
COMMENT=	Inflate/deflate columns to Authen::Passphrase instances

RUN_DEPENDS=	p5-DBIx-Class-DynamicDefault>=0.03:${PORTSDIR}/databases/p5-DBIx-Class-DynamicDefault \
		p5-DBIx-Class>=0.08009:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Authen-Passphrase>=0:${PORTSDIR}/security/p5-Authen-Passphrase
BUILD_DEPENDS:=	p5-DBIx-Class-DynamicDefault>=0.03:${PORTSDIR}/databases/p5-DBIx-Class-DynamicDefault \
		p5-DBIx-Class>=0.08009:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Authen-Passphrase>=0:${PORTSDIR}/security/p5-Authen-Passphrase

PERL_CONFIGURE=	yes

MAN3=		DBIx::Class::InflateColumn::Authen::Passphrase.3

.include <bsd.port.mk>
