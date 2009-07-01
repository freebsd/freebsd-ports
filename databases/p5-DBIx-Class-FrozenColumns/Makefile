# New ports collection makefile for:	p5-DBIx-Class-FrozenColumns
# Date created:		2008-07-22
# Whom:			Vladimir Timofeev <vovkasm@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-FrozenColumns
PORTVERSION=	0.08
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vovkasm@gmail.com
COMMENT=	Store virtual columns inside another column

RUN_DEPENDS=	p5-DBIx-Class>=0.07003:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-Storable>=2.15:${PORTSDIR}/devel/p5-Storable
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::FrozenColumns.3

.include <bsd.port.mk>
