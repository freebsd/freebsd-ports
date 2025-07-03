PORTNAME=	pipelight
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	9
CATEGORIES=	devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Self-hosted, lightweight, CI/CD pipelines

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libssh2.so:security/libssh2

USES=		cargo localbase pkgconfig ssl
USE_GITHUB=	yes
CARGO_INSTALL_PATH=	${PORTNAME}
PLIST_FILES=	bin/pipelight

.include <bsd.port.mk>
