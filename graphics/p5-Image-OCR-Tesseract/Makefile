PORTNAME=	Image-OCR-Tesseract
PORTVERSION=	1.26
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LEOCHARRE
PKGNAMEPREFIX=	p5-

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Read an image with Resseract OCR and get output

LICENSE=	GPLv3

MY_DEPENDS=	tesseract>0:graphics/tesseract \
		ImageMagick6-nox11>0:graphics/ImageMagick6-nox11
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
