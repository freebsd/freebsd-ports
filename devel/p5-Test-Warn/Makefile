# New ports collection makefile for:    p5-Test-Warn
# Date created:				June 18, 2005
# Whom:	      				Brian Minard <bminard@flatfoot.ca>
#
# $FreeBSD$
#

PORTNAME=	Test-Warn
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to test methods for warnings

BUILD_DEPENDS=	${SITE_PERL}/Test/Builder/Tester.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/Array/Compare.pm:${PORTSDIR}/misc/p5-Array-Compare \
		${SITE_PERL}/Sub/Uplevel.pm:${PORTSDIR}/devel/p5-Sub-Uplevel \
		${SITE_PERL}/Tree/DAG_Node.pm:${PORTSDIR}/devel/p5-Tree-DAG_Node
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		Test::Warn.3

.include <bsd.port.mk>
