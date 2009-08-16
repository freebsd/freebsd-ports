# New ports collection makefile for:	databases/p5-DBIx-Class-DateTime-Epoch
# Date created:				29 Mar 2009
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-DateTime-Epoch
PORTVERSION=	0.05
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatic inflation/deflation of epoch-based DateTime objects

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::DateTime::Epoch.3

.include <bsd.port.mk>
