# New ports collection makefile for:	p5-Module-Install-XSUtil
# Date created:		2011-08-15
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Install-XSUtil
PORTVERSION=	0.42
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility functions for XS modules

BUILD_DEPENDS=	p5-Module-Install>=0.91:${PORTSDIR}/devel/p5-Module-Install
RUN_DEPENDS=	p5-Module-Install>=0.91:${PORTSDIR}/devel/p5-Module-Install

TEST_DEPENDS=	p5-B-Hooks-OP-Annotation>=0.43:${PORTSDIR}/devel/p5-B-Hooks-OP-Annotation

PERL_CONFIGURE=	yes

MAN3=		Module::Install::XSUtil.3

.include <bsd.port.mk>
