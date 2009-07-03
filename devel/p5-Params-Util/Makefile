# New ports collection makefile for:	devel/p5-Params-Util
# Date created:				4 July 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Params-Util
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Utility functions to aid in parameter checking

PERL_CONFIGURE=	yes

MAN3=		Params::Util.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
