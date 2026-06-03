PORTNAME=	mmdr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Fast native Rust Mermaid diagram renderer
WWW=		https://github.com/1jehuang/mermaid-rs-renderer

LICENSE=	APACHE20 BSD0CLAUSE BSD2CLAUSE BSD3CLAUSE MIT UNICODE UNLICENSE \
		ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_UNICODE=	UNICODE, INC. LICENSE AGREEMENT - DATA FILES AND SOFTWARE
LICENSE_TEXT_UNICODE=	See https://www.unicode.org/copyright.html
LICENSE_PERMS_UNICODE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	1jehuang
GH_PROJECT=	mermaid-rs-renderer

PLIST_FILES=	bin/mmdr

.include <bsd.port.mk>
