# New ports collection makefile for:	p5-DBIx-Class-Cursor-Cached
# Date created:		2011-06-12
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-Cursor-Cached
PORTVERSION=	1.001.001
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cursor class with built-in caching support

BUILD_DEPENDS=	p5-Carp-Clan>=6.0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-DBIx-Class>=0.08124:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	p5-Carp-Clan>=6.0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-DBIx-Class>=0.08124:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1

TEST_DEPENDS=	p5-Cache-Cache>=0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

USE_PERL5=	configure
USES=		perl5

MAN3=		DBIx::Class::Cursor::Cached.3

.include <bsd.port.mk>
