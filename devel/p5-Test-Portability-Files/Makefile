# New ports collection makefile for:	p5-Test-Portability-Files
# Date created:		2008-02-08
# Whom:			Felippe de Meirelles Motta <lippemail@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Test-Portability-Files
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippemail@gmail.com
COMMENT=	Test::Portability::Files Check file names portability

BUILD_DEPENDS+=	${SITE_PERL}/Test/Builder.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS+=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::Portability::Files.3

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
