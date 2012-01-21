# New ports collection makefile for:	Tree::Parser
# Date created:				1 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Tree-Parser
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Module to parse formatted files into tree structures

BUILD_DEPENDS=	${SITE_PERL}/Array/Iterator.pm:${PORTSDIR}/devel/p5-Array-Iterator \
		${SITE_PERL}/Tree/Simple.pm:${PORTSDIR}/devel/p5-Tree-Simple \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

MAN3=		Tree::Parser.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
