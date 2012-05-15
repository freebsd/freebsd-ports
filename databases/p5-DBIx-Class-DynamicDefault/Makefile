# New ports collection makefile for:	databases/p5-DBIx-Class-DynamicDefault
# Date created:				28 April 2009
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-DynamicDefault
PORTVERSION=	0.04
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatically set and update fields

BUILD_DEPENDS=	p5-DBIx-Class>=0.08127:${PORTSDIR}/databases/p5-DBIx-Class
RUN_DEPENDS=	p5-DBIx-Class>=0.08127:${PORTSDIR}/databases/p5-DBIx-Class

TEST_DEPENDS=	p5-DBICx-TestDatabase>=0:${PORTSDIR}/databases/p5-DBICx-TestDatabase

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::DynamicDefault.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
RUN_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>
