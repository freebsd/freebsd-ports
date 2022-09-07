PORTNAME=	Image-PNG-QRCode
DISTVERSION=	0.10
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Make a PNG image containing a QR code from text
WWW=		https://metacpan.org/pod/Image::PNG::QRCode

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:graphics/png

USES=		perl5
USE_PERL5=	configure

post-patch:
	${REINPLACE_CMD} -e 's|INC => $$vars->{inc}|INC => "-I${LOCALBASE}/include"|g' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
