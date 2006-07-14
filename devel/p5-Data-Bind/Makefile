# ex:ts=8
# Ports collection makefile for:	Data-Bind
# Date created:			Jul. 12, 2006
# Whom:				Ying-Chieh Chen
#
# $FreeBSD$
#

PORTNAME=	Data-Bind
PORTVERSION=	0.27
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A perl module to bind and alias variables

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor	\
		${SITE_PERL}/${PERL_ARCH}/Devel/Caller.pm:${PORTSDIR}/devel/p5-Devel-Caller \
		${SITE_PERL}/${PERL_ARCH}/Devel/LexAlias.pm:${PORTSDIR}/devel/p5-Devel-LexAlias \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Data::Bind.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
