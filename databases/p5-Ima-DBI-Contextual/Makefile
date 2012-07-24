# New ports collection makefile for:	Ima-DBI-Contextual
# Date created:				8 June 2010
# Whom:					Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	Ima-DBI-Contextual
PORTVERSION=	1.006
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JOHND
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lightweight context-aware dbi handle cache and utility methods

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=1.614:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	p5-DBI>=1.614:${PORTSDIR}/databases/p5-DBI

TEST_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

DEPRECATED=	deprecated by upstream

PERL_CONFIGURE=	yes

MAN3=		Ima::DBI::Contextual.3

.include <bsd.port.mk>
