# New ports collection makefile for:	p5-Git-Wrapper
# Date created:		2010-11-12
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Git-Wrapper
PORTVERSION=	0.014
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Wrap git(7) command-line interface

BUILD_DEPENDS=	git>=0:${PORTSDIR}/devel/git
RUN_DEPENDS=	git>=0:${PORTSDIR}/devel/git \
		p5-File-pushd>=0:${PORTSDIR}/devel/p5-File-pushd

PERL_CONFIGURE=	yes

MAN3=		Git::Wrapper.3

.include <bsd.port.mk>
