PORTNAME=	ekphos
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.0
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Lightweight, fast, terminal-based markdown research tool
WWW=		https://www.ekphos.xyz/

LICENSE=	APACHE20 BSD0CLAUSE BSD2CLAUSE BSD3CLAUSE BSL CC0-1.0 CDLA20 \
		ISCL MIT MPL20 UNICODE UNLICENSE ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_CDLA20=	Community Data License Agreement – Permissive, Version 2.0
LICENSE_NAME_UNICODE=	UNICODE, INC. LICENSE AGREEMENT - DATA FILES AND SOFTWARE
LICENSE_TEXT_CDLA20=	See https://cdla.dev/permissive-2-0/
LICENSE_TEXT_UNICODE=	See https://www.unicode.org/copyright.html
LICENSE_PERMS_CDLA20=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_UNICODE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	hanebox

PLIST_FILES=	bin/ekphos

.include <bsd.port.mk>
