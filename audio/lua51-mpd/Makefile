# $FreeBSD$

PORTNAME=	mpd
PORTVERSION=	0.1
CATEGORIES=	audio
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	demelier.david@gmail.com
COMMENT=	A Lua library for musicpd

RUN_DEPENDS=	${LUA_MODLIBDIR}/socket/core.so:${PORTSDIR}/net/luasocket

OPTIONS_DEFINE=	DOCS
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}

.include <bsd.port.options.mk>

GH_ACCOUNT=	silentbicycle
GH_PROJECT=	lua-mpd
GH_TAGNAME=	v0.1

USE_GITHUB=	yes
NO_STAGE=	yes
USE_LUA=	5.1

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-lua-${PORTNAME}-ca32f43

do-build:
	@${DO_NADA}

do-install:
	@${MKDIR} ${LUA_MODSHAREDIR}
	@${INSTALL_DATA} ${WRKSRC}/mpd.lua ${LUA_MODSHAREDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR} ${DOCSDIR}/modules ${DOCSDIR}/files
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/luadoc.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/files/mpd.html ${DOCSDIR}/files
	${INSTALL_DATA} ${WRKSRC}/modules/mpd.html ${DOCSDIR}/modules
.endif

.include <bsd.port.mk>
