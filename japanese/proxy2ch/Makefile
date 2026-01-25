PORTNAME=	proxy2ch
DISTVERSION=	20250614
PORTREVISION=	1
CATEGORIES=	japanese www
MASTER_SITES=	https://codeberg.org/NanashiNoGombe/${PORTNAME}/archive/v${DISTVERSION}${EXTRACT_SUFX}?dummy=/
DISTNAME=	v${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Proxy server for 5ch.net, bbspink.com and talk.jp
WWW=		https://codeberg.org/NanashiNoGombe/proxy2ch/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gmake iconv:wchar_t localbase:ldflags ssl
USE_RC_SUBR=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST_FILES=	${DOCSDIR_REL}/README.md sbin/${PORTNAME}

OPTIONS_DEFINE=	LUA MITM
MITM_DESC=	Operates as a MITM proxy (experimental)

LUA_USES=	lua
LUA_CFLAGS=	-DUSE_LUA
LUA_LDFLAGS=	-llua-${LUA_VER}
MITM_CFLAGS=	-DUSE_MITM -DUSE_ECDSA_KEY
MITM_LDFLAGS=	-lssl

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch-LUA-on:
	@cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e '/include/s,lua.hpp,${LUA_FLAVOR}/lua.hpp,' \
		BBS2chProxyHttpHeaders.h BBS2chProxyPoster.cpp main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
