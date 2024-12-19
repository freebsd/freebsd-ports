PORTNAME=	ox
DISTVERSION=	0.7.5
CATEGORIES=	editors
PKGNAMESUFFIX=	-text-editor

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Independent Rust text editor that runs in your terminal
WWW=		https://github.com/curlpipe/ox/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails, see https://github.com/zhiburt/ptyprocess/issues/17

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	curlpipe

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
