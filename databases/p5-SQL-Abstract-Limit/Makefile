# New ports collection makefile for:	SQL-Abstract-Limit
# Date created:		14 Aug 2005
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SQL-Abstract-Limit
PORTVERSION=	0.141
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	SQL Portability layer for LIMIT emulation

RUN_DEPENDS=	p5-SQL-Abstract>=1.24:${PORTSDIR}/databases/p5-SQL-Abstract \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		SQL::Abstract::Limit.3

.include <bsd.port.mk>
