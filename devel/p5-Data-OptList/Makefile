# New ports collection makefile for:	devel/p5-Data-OptList
# Date created:				6/6/6
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-OptList
PORTVERSION=	0.102
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Parse and validate simple name/value option pairs

BUILD_DEPENDS=	p5-Sub-Install>=0.92:${PORTSDIR}/devel/p5-Sub-Install \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Params-Util>=0.14:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Data::OptList.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
