# New ports collection makefile for:	p5-Devel-PatchPerl
# Date created:		2012-04-07
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-PatchPerl
PORTVERSION=	0.74
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to patch perl source

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-pushd>=1.00:${PORTSDIR}/devel/p5-File-pushd
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		patchperl.1
MAN3=		Devel::PatchPerl.3 \
		Devel::PatchPerl::Hints.3 \
		Devel::PatchPerl::Plugin.3

.include <bsd.port.mk>
