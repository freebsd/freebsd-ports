# New ports collection makefile for:	p5-Set-Infinite
# Date created:	   26 june 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Set-Infinite
PORTVERSION=	0.50
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Set
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Set::Infinite - Sets of intervals

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Set::Infinite.3 Set::Infinite::Basic.3 Set::Infinite::Date.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE="Need at least perl 5.6.1 to build"
.endif

.include <bsd.port.post.mk>
