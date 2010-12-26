# New ports collection makefile for:	SQL::Abstract::Plugin::InsertMulti
# Date created:		26 Dec 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SQL-Abstract-Plugin-InsertMulti
PORTVERSION=	0.03
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to add bulk insert for SQL::Abstract

RUN_DEPENDS=	\
	p5-SQL-Abstract>=1.6:${PORTSDIR}/databases/p5-SQL-Abstract \
	p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	SQL::Abstract::Plugin::InsertMulti.3

.include <bsd.port.mk>
