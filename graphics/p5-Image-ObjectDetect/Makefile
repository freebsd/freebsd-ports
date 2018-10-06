# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	Image-ObjectDetect
PORTVERSION=	0.12
PORTREVISION=	5
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Detects objects from picture using opencv

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/opencv.pc:graphics/opencv

USE_PERL5=	configure
USES=		perl5 pkgconfig

.include <bsd.port.mk>
