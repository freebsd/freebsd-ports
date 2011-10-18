# New ports collection makefile for:	p5-Cairo-GObject
# Date created:		2011-10-17
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Cairo-GObject
PORTVERSION=	1.001
CATEGORIES=	devel graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TSCH
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Integrate Cairo into the Glib type system

BUILD_DEPENDS=	cairo>=1.10.0:${PORTSDIR}/graphics/cairo \
		p5-Cairo>=1.080:${PORTSDIR}/graphics/p5-Cairo \
		p5-ExtUtils-Depends>=0.200:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=1.224:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS=	cairo>=1.10.0:${PORTSDIR}/graphics/cairo \
		p5-Cairo>=1.080:${PORTSDIR}/graphics/p5-Cairo \
		p5-Glib2>=1.224:${PORTSDIR}/devel/p5-Glib2

PERL_CONFIGURE=	yes

MAN3=		Cairo::GObject.3

.include <bsd.port.mk>
