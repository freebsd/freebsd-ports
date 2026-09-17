PORTNAME=	tatuin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.27.0
CATEGORIES=	deskutils

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Task Aggregator TUI for N providers
WWW=		https://github.com/panter-dsd/tatuin/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	panter-dsd

PLIST_FILES=	bin/tatuin

# Build with system OpenSSL instead of vendored one
post-patch:
	@${REINPLACE_CMD} -e '/openssl =/s/"vendored"//' ${WRKSRC}/Cargo.toml

.include <bsd.port.mk>
