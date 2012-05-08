# New ports collection makefile for:	InlineX::CPP2XS
# Date created:				30 Jan, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	InlineX-CPP2XS
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SISYPHUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert from Inline C++ code to XS

BUILD_DEPENDS=	p5-Inline>=0.50:${PORTSDIR}/devel/p5-Inline \
		p5-Inline-CPP>=0.39:${PORTSDIR}/devel/p5-Inline-CPP
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		InlineX::CPP2XS.3 InlineX::CPP2XS-Cookbook.3

.include <bsd.port.mk>
