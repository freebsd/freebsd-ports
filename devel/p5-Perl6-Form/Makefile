# New ports collection makefile for:	devel/p5-Perl6-Form
# Date created:				21 Oct 2004
# Whom:					Yuan-Chung Hsiao <ychsiao@ychsiao.idv.tw>
#
# $FreeBSD$
#

PORTNAME=	Perl6-Form
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/D/DC/DCONWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Implements the Perl 6 'form' built-in

BUILD_DEPENDS=	${SITE_PERL}/Perl6/Export.pm:${PORTSDIR}/devel/p5-Perl6-Export \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Perl6::Form.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This program only support perl 5.8.0 or above
.endif

.include <bsd.port.post.mk>
