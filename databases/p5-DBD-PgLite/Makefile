# New ports collection makefile for:	databases/p5-DBD-PgLite
# Date created:				03 November 2008
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-PgLite
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	PostgreSQL emulation mode for SQLite

RUN_DEPENDS=	p5-DBD-SQLite>=1.0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Text-Iconv>=1.0:${PORTSDIR}/converters/p5-Text-Iconv \
		p5-DBI>=1.30:${PORTSDIR}/databases/p5-DBI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBD::PgLite.3 \
	DBD::PgLite::MirrorPgToSQLite.3

.include <bsd.port.mk>
