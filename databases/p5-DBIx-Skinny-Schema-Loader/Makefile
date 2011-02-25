# New ports collection makefile for:	DBIx::Skinny::Schema::Loader
# Date created:		20 Nov 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Skinny-Schema-Loader
PORTVERSION=	0.22
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/N/NE/NEKOYA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to load schema for DBIx::Skinny

RUN_DEPENDS=	\
	p5-DBIx-Skinny>=0.0733:${PORTSDIR}/databases/p5-DBIx-Skinny
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Skinny::Schema::Loader.3

.include <bsd.port.mk>
