# $FreeBSD$

PORTNAME=	Image-PNG-Libpng
DISTVERSION=	0.45
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the C library "libpng"

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libpng.so:graphics/png

USES=		perl5
USE_PERL5=	configure

post-patch:
	${REINPLACE_CMD} -e 's|#  *INC  *=>  *$$inc|INC => "-I${LOCALBASE}/include"|' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
