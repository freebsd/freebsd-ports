PORTNAME=	libimagequant
PORTVERSION=	4.4.1
CATEGORIES=	graphics

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Image Quantization Library
WWW=		https://pngquant.org/lib/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	cargo-cbuild:devel/cargo-c

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	ImageOptim

USE_LDCONFIG=	yes

CARGO_BUILD_ARGS=	--package imagequant-sys
CARGO_INSTALL_ARGS:=	${CARGO_BUILD_ARGS}

PLIST_FILES=	include/libimagequant.h \
		lib/libimagequant.a \
		lib/libimagequant.so \
		lib/libimagequant.so.${SOVERSION:R} \
		lib/libimagequant.so.${SOVERSION} \
		libdata/pkgconfig/imagequant.pc

SOVERSION=	0.4.1

do-build:
	@${CARGO_CARGO_RUN} cbuild \
		--verbose \
		--verbose \
		${CARGO_BUILD_ARGS}

do-install:
	@${CARGO_CARGO_RUN} cinstall \
		--verbose \
		--verbose \
		--destdir "${STAGEDIR}" \
		--prefix "${PREFIX}" \
		${CARGO_INSTALL_ARGS}

.include <bsd.port.mk>
