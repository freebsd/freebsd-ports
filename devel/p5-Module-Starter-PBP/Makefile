# New ports collection makefile for:	devel/p5-Module-Starter-PBP
# Date created:				12 September 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Starter-PBP
PORTVERSION=	0.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Create a module as recommended in "Perl Best Practices"

BUILD_DEPENDS=	${SITE_PERL}/Module/Starter.pm:${PORTSDIR}/devel/p5-Module-Starter \
		${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Module::Starter::PBP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
