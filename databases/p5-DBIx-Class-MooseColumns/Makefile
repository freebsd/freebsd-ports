# New ports collection makefile for:	DBIx::Class::MooseColumns
# Date created:		2010-11-20
# Whom:			Andrej Zverev <az@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-MooseColumns
PORTVERSION=	0.18
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MENDEL
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	Allow write DBIC add_column definitions as attribute options

RUN_DEPENDS=	p5-Moose>=1.19:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-autoclean>=0.09:${PORTSDIR}/devel/p5-namespace-autoclean

PERL_CONFIGURE=	5.8.9+

MAN3=	\
	DBIx::Class::MooseColumns.3 \
	DBIx::Class::MooseColumns::Meta::Role::Attribute.3 \
	DBIx::Class::MooseColumns::Meta::Role::Attribute::DBICColumn.3 \
	DBIx::Class::MooseColumns::Meta::Role::Attribute::DBICColumn::Inflated.3

.include <bsd.port.mk>
