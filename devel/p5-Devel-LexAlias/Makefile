# ex:ts=8
# Ports collection makefile for:	Devel-LexAlias
# Date created:			Jul. 12, 2006
# Whom:				Ying-Chieh Chen
#
# $FreeBSD$
#

PORTNAME=	Devel-LexAlias
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A perl module which does alias lexical variables

BUILD_DEPENDS=	p5-Devel-Caller>=0.03:${PORTSDIR}/devel/p5-Devel-Caller
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Devel::LexAlias.3

.include <bsd.port.mk>
