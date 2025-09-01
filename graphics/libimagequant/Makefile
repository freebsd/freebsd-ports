PORTNAME=	libimagequant
PORTVERSION=	4.3.4
PORTREVISION=	5
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image Quantization Library
WWW=		https://pngquant.org/lib/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	cargo-cbuild:devel/cargo-c

USES=		cargo
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	ImageOptim
CARGO_BUILD_ARGS=	--package imagequant-sys
CARGO_INSTALL_ARGS:=	${CARGO_BUILD_ARGS}
PLIST_FILES=	include/libimagequant.h \
		lib/libimagequant.a \
		lib/libimagequant.so \
		lib/libimagequant.so.0.4 \
		lib/libimagequant.so.0.4.0 \
		libdata/pkgconfig/imagequant.pc

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
