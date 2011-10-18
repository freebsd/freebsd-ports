# New ports collection makefile for:	p5-Cairo
# Date created:		2005-08-18
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/p5-Cairo/Makefile,v 1.8 2007/02/16 18:14:25 mezz Exp $
#

PORTNAME=	Cairo
PORTVERSION=	1.081
CATEGORIES=	graphics perl5
MASTER_SITES=	SF/gtk2-perl/${PORTNAME}/${PORTVERSION} \
		CPAN
MASTER_SITE_SUBDIR=	CPAN:TSCH
PKGNAMEPREFIX=	p5-

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Perl bindings to the cairo graphics library

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.200:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Number-Delta>=1:${PORTSDIR}/devel/p5-Test-Number-Delta

PERL_CONFIGURE=	yes

MAN3=	Cairo.3

.include <bsd.port.mk>
