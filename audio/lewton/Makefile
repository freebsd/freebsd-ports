PORTNAME=	lewton
DISTVERSION=	0.10.2
PORTREVISION=	24
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	05f96f6e6976.patch:-p1 # https://github.com/RustAudio/lewton/pull/97

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Rust vorbis decoder
WWW=		https://github.com/RustAudio/lewton

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cargo-cbuild:devel/cargo-c

USES=		cargo
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	RustAudio
PLIST_SUB=	VERSION=${DISTVERSION:C/-.*//}

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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
