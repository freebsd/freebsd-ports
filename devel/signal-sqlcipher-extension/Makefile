PORTNAME=	signal-sqlcipher-extension
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Sqlcipher extension for crypto provider
WWW=		https://github.com/signalapp/Signal-FTS5-Extension

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
GH_PROJECT=	Signal-Sqlcipher-Extension

PLIST_FILES=	lib/libsignal_sqlcipher_extension.a \
		include/signal-tokenizer.h

do-install:
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/*/libsignal_sqlcipher_extension.a ${STAGEDIR}${LOCALBASE}/lib/
	${INSTALL_DATA} ${WRKSRC}/target/signal-tokenizer.h ${STAGEDIR}${LOCALBASE}/include/

.include <bsd.port.mk>
