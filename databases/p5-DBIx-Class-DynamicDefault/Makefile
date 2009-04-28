# New ports collection makefile for:	databases/p5-DBIx-Class-DynamicDefault
# Date created:				28 April 2009
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-DynamicDefault
PORTVERSION=	0.03
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Automatically set and update fields

RUN_DEPENDS=	p5-parent>=0:${PORTSDIR}/devel/p5-parent \
		p5-DBIx-Class>=0.08009:${PORTSDIR}/databases/p5-DBIx-Class
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::DynamicDefault.3

.include <bsd.port.mk>
