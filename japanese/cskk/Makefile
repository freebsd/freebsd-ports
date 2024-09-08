PORTNAME=	cskk
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1
PORTREVISION=	4
CATEGORIES=	japanese

MAINTAINER=	syobon@syobon.net
COMMENT=	SKK (Simple Kana Kanji henkan) library
WWW=		https://github.com/naokiri/cskk

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	cargo-cbuild:devel/cargo-c
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cargo localbase:ldflags
USE_LDCONFIG=	${PREFIX}/lib/cskk
USE_GITHUB=	yes
GH_ACCOUNT=	naokiri

do-build:
	@${CARGO_CARGO_RUN} cbuild ${CARGO_BUILD_ARGS}

do-install:
	@${CARGO_CARGO_RUN} cinstall \
		--destdir "${STAGEDIR}" \
		--prefix "${PREFIX}" \
		--pkgconfigdir "${PREFIX}/libdata/pkgconfig" \
		${CARGO_INSTALL_ARGS}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/cskk/*.so

.include <bsd.port.mk>
