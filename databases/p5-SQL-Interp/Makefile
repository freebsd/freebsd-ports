# New ports collection makefile for:	SQL-Interp
# Date created:	                        16 Jan 2008
# Whom:		                        Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SQL-Interp
PORTVERSION=	1.21
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Interpolate Perl variables into SQL with DBI

BUILD_DEPENDS=	p5-DBI>=1:${PORTSDIR}/databases/p5-DBI \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS=	p5-DBI>=1:${PORTSDIR}/databases/p5-DBI \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter

PERL_CONFIGURE=	yes

MAN3=		DBIx::Interp.3 SQL::Interp.3

.include <bsd.port.mk>
