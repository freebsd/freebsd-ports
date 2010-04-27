# New ports collection makefile for:	p5-Test-Pod
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Test-Pod
PORTVERSION=	1.44
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Check for POD errors in files

BUILD_DEPENDS=	${SITE_PERL}/Pod/Simple.pm:${PORTSDIR}/textproc/p5-Pod-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Test::Pod.3

.include <bsd.port.mk>
