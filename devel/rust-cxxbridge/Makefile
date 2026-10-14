PORTNAME=	cxxbridge
PORTVERSION=	1.0.199
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://crates.io/api/v1/crates/${PORTNAME}-cmd/${PORTVERSION}/download?dummy=/
PKGNAMEPREFIX=	rust-
DISTNAME=	${PORTNAME}-cmd-${PORTVERSION}
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Generator for C++ bindings of the Rust cxx crate
WWW=		https://cxx.rs/

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo

PLIST_FILES=	bin/cxxbridge

# The version must match the cxx crate version used by dependent ports
# (e.g. deskutils/taskwarrior) since corrosion only accepts an exact match.
PORTSCOUT=	limitw:1

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/cxxbridge \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
