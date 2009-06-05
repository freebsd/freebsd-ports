# New ports collection makefile for:	p5-B-Hooks-Parser
# Date created:		2009-03-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	B-Hooks-Parser
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	B
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to perls parser variables

BUILD_DEPENDS=	p5-B-Hooks-OP-Check>0:${PORTSDIR}/devel/p5-B-Hooks-OP-Check:patch \
		p5-ExtUtils-Depends>0:${PORTSDIR}/devel/p5-ExtUtils-Depends
RUN_DEPENDS=	p5-B-Hooks-OP-Check>0:${PORTSDIR}/devel/p5-B-Hooks-OP-Check \
		p5-parent>:${PORTSDIR}/devel/p5-parent

PERL_CONFIGURE=	yes

MAN3=		B::Hooks::Parser.3

.include <bsd.port.mk>
