# New ports collection makefile for:	SQL-Interp
# Date created:	                        16 Jan 2008
# Whom:		                        Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SQL-Interp
PORTVERSION=	1.10
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Interpolate Perl variables into SQL with DBI

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes

MAN3=		DBIx::Interp.3 SQL::Interp.3

.include <bsd.port.mk>
