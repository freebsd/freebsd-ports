PORTNAME=	radiotrope
DISTVERSION=	g20260316
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	AI agent-enabled internet radio player
WWW=		https://github.com/goten002/radiotrope

LICENSE=	APACHE20 BSD0CLAUSE BSD2CLAUSE BSD3CLAUSE BSL FDK-AAC GPLv3 \
		ISCL MIT MPL20 UNICODE UNLICENSE WTFPL ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_FDK-AAC=	Fraunhofer FDK AAC Codec Library
LICENSE_NAME_UNICODE=	UNICODE, INC. LICENSE AGREEMENT - DATA FILES AND SOFTWARE
LICENSE_TEXT_FDK-AAC=	See https://spdx.org/licenses/FDK-AAC.html
LICENSE_TEXT_UNICODE=	See https://www.unicode.org/copyright.html
LICENSE_PERMS_FDK-AAC=	dist-mirror pkg-mirror auto-accept
LICENSE_PERMS_UNICODE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	goten002
GH_TAGNAME=	aab2334

CARGO_INSTALL_PATH=	crates/radiotrope-app crates/radiotrope-cli

DESKTOP_ENTRIES=	"${PORTNAME}" \
			"${COMMENT}" \
			"${PORTNAME}" \
			"${PORTNAME}" \
			"Audio;AudioVideo;" \
			false

post-install:
.for size in 16 32 48 64 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	cd ${WRKSRC}/assets/icons && \
	${INSTALL_DATA} icon-${size}.png \
	${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor

.include <bsd.port.mk>
