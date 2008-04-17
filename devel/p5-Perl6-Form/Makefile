# New ports collection makefile for:	devel/p5-Perl6-Form
# Date created:				21 Oct 2004
# Whom:					Yuan-Chung Hsiao <ychsiao@ychsiao.idv.tw>
#
# $FreeBSD$
#

PORTNAME=	Perl6-Form
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Implements the Perl 6 'form' built-in

BUILD_DEPENDS=	${SITE_PERL}/Perl6/Export.pm:${PORTSDIR}/devel/p5-Perl6-Export \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Perl6::Form.3

.include <bsd.port.mk>
