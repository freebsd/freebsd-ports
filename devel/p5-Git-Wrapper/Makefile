# New ports collection makefile for:	p5-Git-Wrapper
# Date created:		2010-11-12
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Git-Wrapper
PORTVERSION=	0.017
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Wrap git(7) command-line interface

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	git>=0:${PORTSDIR}/devel/git \
		p5-Sort-Versions>=0:${PORTSDIR}/devel/p5-Sort-Versions \
		p5-File-pushd>=0:${PORTSDIR}/devel/p5-File-pushd
RUN_DEPENDS=	git>=0:${PORTSDIR}/devel/git \
		p5-Sort-Versions>=0:${PORTSDIR}/devel/p5-Sort-Versions \
		p5-File-pushd>=0:${PORTSDIR}/devel/p5-File-pushd

TEST_DEPENDS=	p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep

PERL_CONFIGURE=	yes

MAN3=		Git::Wrapper.3

.include <bsd.port.mk>
