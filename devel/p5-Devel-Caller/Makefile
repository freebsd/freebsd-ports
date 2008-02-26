# ex:ts=8
# Ports collection makefile for:	Devel-Caller
# Date created:			Jul. 11, 2006
# Whom:				Ying-Chieh Chen
#
# $FreeBSD$
#

PORTNAME=	Devel-Caller
PORTVERSION=	2.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A perl module which is meatier versions of caller

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/PadWalker.pm:${PORTSDIR}/devel/p5-PadWalker
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Devel::Caller.3

.include <bsd.port.mk>
