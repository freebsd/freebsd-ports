# New ports collection makefile for:	p5-Module-Pluggable-Ordered
# Date created:		2004-08-29
# Whom:			Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Pluggable-Ordered
PORTVERSION=	1.2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Call module plugins in a specified order

BUILD_DEPENDS=	${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-exports
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Module::Pluggable::Ordered.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
EXTRA_PATCHES=	${PATCHDIR}/5.005_03-*
.endif
.include <bsd.port.post.mk>
