# New ports collection makefile for:	devel/p5-Test-Group
# Date created:				10 April 2007
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Group
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Group together related tests in a test suite

RUN_DEPENDS=	p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Test::Group.3

.include <bsd.port.mk>
