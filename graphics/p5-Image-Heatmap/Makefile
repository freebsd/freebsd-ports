# New ports collection makefile for:	p5-Image-Heatmap
# Date created:		2009-07-20
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Heatmap
PORTVERSION=	0.565
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Convert geographic coordinates into a graphical heatmap

LICENSE_COMB=	dual
LICENSE=	ART20 GPLv1

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

WRKSRC=	${WRKDIR}/${PORTNAME}
PERL_CONFIGURE=	yes

MAN3=	Image::Heatmap.3

.include <bsd.port.mk>
