# New ports collection makefile for:	p5-Tie-ToObject
# Date created:		2008-02-13
# Whom:			Felippe de Meirelles Motta <lippemail@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Tie-ToObject
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippemail@gmail.com
COMMENT=	Tie to an existing object

BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/use/ok.pm:${PORTSDIR}/devel/p5-Test-use-ok \
		${SITE_PERL}/Tie/RefHash.pm:${PORTSDIR}/devel/p5-Tie-RefHash
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/use/ok.pm:${PORTSDIR}/devel/p5-Test-use-ok \
		${SITE_PERL}/Tie/RefHash.pm:${PORTSDIR}/devel/p5-Tie-RefHash

PERL_CONFIGURE=	yes

MAN3=		Tie::ToObject.3

.include <bsd.port.mk>
