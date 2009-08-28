# Ports collection makefile for:	Layout-Manager
# Date created:				2008/08/30
# Whom:	      				chinsan
#
# $FreeBSD$
#

PORTNAME=	Layout-Manager
PORTVERSION=	0.30
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/G/GP/GPHAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	2D Layout Management

BUILD_DEPENDS=	p5-Moose>=0.54:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-AttributeHelpers>=0.12:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
		p5-Module-Install>=0.64:${PORTSDIR}/devel/p5-Module-Install \
		p5-Geometry-Primitive>=0.13:${PORTSDIR}/graphics/p5-Geometry-Primitive \
		p5-Graphics-Primitive>=0.34:${PORTSDIR}/graphics/p5-Graphics-Primitive
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Layout::Manager.3 \
		Layout::Manager::Absolute.3 \
		Layout::Manager::Axis.3 \
		Layout::Manager::Compass.3 \
		Layout::Manager::Flow.3 \
		Layout::Manager::Grid.3 \
		Layout::Manager::Single.3

.include <bsd.port.mk>
