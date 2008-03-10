# New ports collection makefile for:	p5-ExtUtils-Manifest
# Date created:		2008-02-11
# Whom:			Felippe de Meirelles Motta <lippemail@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-Manifest
PORTVERSION=	1.51
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Utilities to write and check a MANIFEST file

BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools

PERL_CONFIGURE=	yes

MAN3=		ExtUtils::Manifest.3
.include <bsd.port.mk>
