# New ports collection makefile for:	Mason
# Date created:				03 April, 2012
# Whom:					Muhammad Moinur Rahman <5u623l20@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Test-Class-Most
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:OVID
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Test Classes the easy way

BUILD_DEPENDS=	p5-Test-Class>0:${PORTSDIR}/devel/p5-Test-Class \
		p5-Test-Most>0:${PORTSDIR}/devel/p5-Test-Most

PERL_MODBUILD=	yes

PLIST_FILES=	%%SITE_PERL%%/Test/Class/Most.pm
PLIST_DIRSTRY=	%%SITE_PERL%%/Test/Class %%SITE_PERL%%/Test

MAN3=		Test::Class::Most.3

.include <bsd.port.mk>
