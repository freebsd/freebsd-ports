# Created by: Don Owens <don@regexguy.com>
# $FreeBSD$

PORTNAME=	DBIx-Wrapper
PORTVERSION=	0.28
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	don@regexguy.com
COMMENT=	A wrapper around Perl's DBI module

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI

USES=		perl5
USE_PERL5=	configure

MAN3=		DBIx::Wrapper.3 \
		DBIx::Wrapper::Request.3

NO_STAGE=	yes
.include <bsd.port.mk>
