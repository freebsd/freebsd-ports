# New ports collection makefile for:	p5-Cairo
# Date created:		2005-08-18
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/p5-Cairo/Makefile,v 1.8 2007/02/16 18:14:25 mezz Exp $
#

PORTNAME=	Cairo
PORTVERSION=	1.061
CATEGORIES=	graphics perl5
MASTER_SITES=	SF/gtk2-perl
PKGNAMEPREFIX=	p5-

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Perl bindings to the cairo graphics library

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/Test/Number/Delta.pm:${PORTSDIR}/devel/p5-Test-Number-Delta
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Cairo.3

.include <bsd.port.mk>
