PORTNAME=	ebur128
DISTVERSION=	0.1.10
PORTREVISION=	7
CATEGORIES=	audio

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Library implementing the EBU R128 loudness standard
WWW=		https://github.com/sdroege/ebur128

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cargo-cbuild:devel/cargo-c

USES=		cargo
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	sdroege

CONFLICTS_INSTALL=	libebur128

do-build:
	@${CARGO_CARGO_RUN} cbuild --verbose --verbose ${CARGO_BUILD_ARGS}

do-install:
	@${CARGO_CARGO_RUN} cinstall --verbose --verbose \
		--destdir "${STAGEDIR}" \
		--prefix "${PREFIX}" \
		${CARGO_INSTALL_ARGS}

.include <bsd.port.mk>
