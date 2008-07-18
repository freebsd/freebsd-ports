# New ports collection makefile for:	SVN::Hook
# Date created:		2008-02-12
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Hook
PORTVERSION=	0.28
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Perl module for managing Subversion hook scripts

RUN_DEPENDS=	${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
BUILD_DEPENDS=	${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor

PERL_CONFIGURE=	yes

MAN1=		svnhook.1
MAN3=		SVN::Hook.3

.include <bsd.port.mk>
