# New ports collection makefile for:	p5-Module-Util
# Date created:		2008-02-25
# Whom:			Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Util
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module name tools and transformations

RUN_DEPENDS=	p5-File-Find-Rule>0:${PORTSDIR}/devel/p5-File-Find-Rule
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	YES

MAN1=	pm_which.1
MAN3=	Module::Util.3

.include <bsd.port.mk>
