# $FreeBSD$

PORTNAME=	DBIx-Class-PassphraseColumn
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fw@moov.de
COMMENT=	Automatically hash password/passphrase columns

RUN_DEPENDS=	p5-DBIx-Class-DynamicDefault>=0.03:databases/p5-DBIx-Class-DynamicDefault \
		p5-DBIx-Class>=0.08009:databases/p5-DBIx-Class
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
