# New ports collection makefile for:	devel/p5-Perl6-Export
# Date created:				21 Oct 2004
# Whom:					Yuan-Chung Hsiao <ychsiao@ychsiao.idv.tw>
#
# $FreeBSD$
#

PORTNAME=	Perl6-Export
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/D/DC/DCONWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Implements the Perl 6 'is export(...)' trait

BUILD_DEPENDS=	${SITE_PERL}/Filter/Simple.pm:${PORTSDIR}/textproc/p5-Filter-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Perl6::Export.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This program only support perl 5.8.0 or above
.endif

.include <bsd.port.post.mk>
