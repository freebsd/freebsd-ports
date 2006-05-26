# New ports collection makefile for:	p5-DBIx-SQLite-Simple
# Date created:		26 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-SQLite-Simple
PORTVERSION=	0.32
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Easy access to SQLite databases using objects

BUILD_DEPENDS=	${SITE_PERL}/Class/Gomor.pm:${PORTSDIR}/devel/p5-Class-Gomor \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::SQLite::Simple.3 \
	DBIx::SQLite::Simple::Table.3

.include <bsd.port.mk>
