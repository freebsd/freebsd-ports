# New ports collection makefile for:	DBIx::Class::AsFdat
# Date created:		18 Mar 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-AsFdat
PORTVERSION=	0.03
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension like CDBI::Plugin::AsFdat

RUN_DEPENDS=	\
	p5-DBIx-Class>0:${PORTSDIR}/databases/p5-DBIx-Class
BUILD_DEPENDS=	\
	p5-DBIx-Class>0:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-Test-Declare>0:${PORTSDIR}/devel/p5-Test-Declare \
	p5-DateTime>0:${PORTSDIR}/devel/p5-DateTime

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::AsFdat.3

.include <bsd.port.mk>
