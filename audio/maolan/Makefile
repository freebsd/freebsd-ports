PORTNAME=	maolan
DISTVERSION=	0.0.3
CATEGORIES=	audio

MAINTAINER=	meka@tilda.center
COMMENT=	Rust digital audio workstation
WWW=		https://maolan.github.io

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS=	libjack.so:audio/jack \
		liblilv-0.so:audio/lilv \
		librubberband.so:audio/rubberband \
		libsuil-0.so:audio/suil

USES=		cargo gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	maolan
GH_TAGNAME=	${DISTVERSION}

USE_GNOME=	glib20 gtk20
USE_XORG=	x11

PLIST_FILES=	bin/${PORTNAME}

do-test:
	@${CARGO_CARGO_RUN} test --manifest-path ${CARGO_CARGOTOML} --verbose \
		${CARGO_TEST_ARGS}
	@${CARGO_CARGO_RUN} test --manifest-path ${CARGO_WRKSRC}/engine/Cargo.toml \
		--verbose ${CARGO_TEST_ARGS}

.include <bsd.port.mk>
