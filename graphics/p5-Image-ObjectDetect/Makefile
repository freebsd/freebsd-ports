PORTNAME=	Image-ObjectDetect
PORTVERSION=	0.12
PORTREVISION=	6
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Detects objects from picture using opencv

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BROKEN=		OpenCV4 no longer ships OpencCV-1.0 headers

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/opencv.pc:graphics/opencv

USE_PERL5=	configure
USES=		perl5 pkgconfig

.include <bsd.port.mk>
