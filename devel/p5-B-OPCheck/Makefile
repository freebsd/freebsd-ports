# New ports collection makefile for:	p5-B-OPCheck
# Date created:		2009-03-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	B-OPCheck
PORTVERSION=	0.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	B
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PL_check hacks using Perl callbacks

RUN_DEPENDS=	p5-B-Utils>=0:${PORTSDIR}/devel/p5-B-Utils \
		p5-Scope-Guard>=0:${PORTSDIR}/devel/p5-Scope-Guard \
		p5-XSLoader>=0:${PORTSDIR}/devel/p5-XSLoader
BUILD_DEPENDS:=	p5-ExtUtils-Depends>=0:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		B::OPCheck.3

.include <bsd.port.mk>
