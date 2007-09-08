# New ports collection makefile for:	Class-DBI-Plugin-Iterator
# Date created:		26 Oct 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Plugin-Iterator
PORTVERSION=	0.13
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AS/ASAKURA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	New iterator for p5-Class-DBI

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI

PERL_CONFIGURE=	yes
MAN3=		Class::DBI::Plugin::Iterator.3 \
		Class::DBI::Plugin::Iterator::Nihongo.3

.include <bsd.port.mk>
