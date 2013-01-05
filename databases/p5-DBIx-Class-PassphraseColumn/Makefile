# $FreeBSD$

PORTNAME=	DBIx-Class-PassphraseColumn
PORTVERSION=	0.02
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	fw@moov.de
COMMENT=	Automatically hash password/passphrase columns

RUN_DEPENDS=	p5-DBIx-Class-DynamicDefault>=0.03:${PORTSDIR}/databases/p5-DBIx-Class-DynamicDefault \
		p5-DBIx-Class>=0.08009:${PORTSDIR}/databases/p5-DBIx-Class
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::PassphraseColumn.3

.include <bsd.port.mk>
