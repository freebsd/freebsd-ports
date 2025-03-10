PORTNAME=	Barcode-ZBar
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to ZBar barcode reader
WWW=		https://metacpan.org/release/Barcode-ZBar

LIB_DEPENDS=	libzbar.so:graphics/zbar

USES=		perl5
USE_PERL5=	configure

CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib -lzbar"

pre-install:
	${STRIP_CMD} ${WRKSRC}/blib/arch/auto/Barcode/ZBar/ZBar.so

.include <bsd.port.mk>
