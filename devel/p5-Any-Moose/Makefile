# New ports collection makefile for:	Any::Moose
# Date created:		23 Feb 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Any-Moose
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/SA/SARTAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for/to use Moose or Mouse modules

PERL_CONFIGURE=	yes

MAN3=	Any::Moose.3

OPTIONS=	MOOSE "Use Moose" off \
		MOUSE "Use Mouse" on

.include <bsd.port.pre.mk>

.if defined(WITH_MOOSE)
RUN_DEPENDS+=	p5-Moose>0:${PORTSDIR}/devel/p5-Moose
.endif

.if defined(WITH_MOUSE)
RUN_DEPENDS+=	p5-Mouse>=0.40:${PORTSDIR}/devel/p5-Mouse
.endif

.include <bsd.port.post.mk>
