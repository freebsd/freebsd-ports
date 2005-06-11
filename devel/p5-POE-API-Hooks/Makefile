# New ports collection makefile for:	POE-API-Hooks
# Date created:	   17 October 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-API-Hooks
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/S/SU/SUNGO
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Implement lightweight hooks into POE

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::API::Hooks.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	Perl 5.6.1 or newer required. Install lang/perl5 or lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
