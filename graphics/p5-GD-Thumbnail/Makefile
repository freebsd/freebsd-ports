# Ports collection makefile for:	GD::Thumbnail
# Date created:			2006/08/15
# Whom:	      			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	GD-Thumbnail
PORTVERSION=	1.33
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Thumbnail maker for GD

BUILD_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		GD::Thumbnail.3

.include <bsd.port.mk>
