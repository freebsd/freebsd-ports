# New ports collection makefile for:	DBIx::Class::ResultSet::RecursiveUpdate
# Date created:		25 Mar 2009
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-ResultSet-RecursiveUpdate
PORTVERSION=	0.010
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Like update_or_create - but recursive

RUN_DEPENDS=	\
	p5-DBIx-Class>=0.08011:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-DBIx-Class-IntrospectableM2M>=0:${PORTSDIR}/databases/p5-DBIx-Class-IntrospectableM2M \
	p5-version>=0:${PORTSDIR}/devel/p5-version \
	p5-SQL-Translator>=0.08:${PORTSDIR}/databases/p5-SQL-Translator \
	p5-DateTime>0:${PORTSDIR}/devel/p5-DateTime
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::ResultSet::RecursiveUpdate.3

.include <bsd.port.mk>
