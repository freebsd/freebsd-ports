# New ports collection makefile for:	InlineX::C2XS
# Date created:		3 Oct 2006
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	InlineX-C2XS
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SISYPHUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module to create an XS file from an Inline C file

BUILD_DEPENDS=	p5-Inline>=0.46:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		InlineX::C2XS.3 InlineX::C2XS-Cookbook.3

.include <bsd.port.mk>
