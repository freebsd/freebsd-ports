PORTNAME=	pipelight
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Self-hosted, lightweight, CI/CD pipelines

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=			cargo localbase pkgconfig
USE_GITHUB=		yes
CARGO_INSTALL_PATH=	${PORTNAME}
PLIST_FILES=		bin/pipelight

post-patch:
	@${REINPLACE_CMD} -e 's|%%VERSION%%|${DISTVERSION}|' \
		${WRKSRC}/cli/Cargo.toml

.include <bsd.port.mk>
