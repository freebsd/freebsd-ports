# New ports collection makefile for:	DBIx::Inspector
# Date created:		26 Dec 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Inspector
PORTVERSION=	0.04
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to get information from $dbh

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Inspector.3 \
	DBIx::Inspector::Column.3 \
	DBIx::Inspector::ForeignKey.3 \
	DBIx::Inspector::Iterator.3 \
	DBIx::Inspector::Table.3

.include <bsd.port.mk>
