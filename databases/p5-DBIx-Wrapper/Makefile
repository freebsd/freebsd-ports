# New ports collection makefile for:   p5-DBIx-Wrapper
# Date created:        8 January 2012
# Whom:                Don Owens <don@regexguy.com>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Wrapper
PORTVERSION=	0.28
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	don@regexguy.com
COMMENT=	A wrapper around Perl's DBI module

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes

MAN3=		DBIx::Wrapper.3 \
		DBIx::Wrapper::Request.3

.include <bsd.port.mk>
