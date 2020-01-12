# $FreeBSD$

PORTNAME=	liquid-dsp
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.3.2
#PORTREVISION=	1
CATEGORIES=	comms

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Software-Defined Radio Digital Signal Processing Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float

USES=		autoreconf:build gmake #gettext-tools iconv:wchar_t libtool

USE_GITHUB=	yes
GH_ACCOUNT=	jgaeddert
GH_TAGNAME=		4892ebb

GNU_CONFIGURE=	yes
MAKEFILE=	makefile
#USE_LDCONFIG=	yes
#INSTALL_TARGET=	install-strip
PORTDOCS=	*

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

pre-configure:
	@cd ${WRKSRC}; ${SH} bootstrap.sh

.include <bsd.port.mk>
