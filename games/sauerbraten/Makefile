# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>

PORTNAME=	sauerbraten
PORTVERSION=	20201221
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2020_11_29
DISTNAME=	${PORTNAME}_2020_12_21_linux

MAINTAINER=	acm@FreeBSD.org
COMMENT=	First person shooter based on Cube

LICENSE=	MIT ZLIB
LICENSE_COMB=	multi

USES=		compiler:c++11-lang gmake tar:bzip2
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	libenet

PORTDATA=	data packages
PORTDOCS=	*
PLIST_DIRS=	%%DATADIR%%/packages/prefab

OPTIONS_MULTI=	BUILD
OPTIONS_MULTI_BUILD=	CLIENT DEDICATED MASTER
OPTIONS_DEFAULT=	CLIENT DEDICATED

SUB_FILES=	pkg-message ${PLIST_FILES:Mbin/*:T}

OPTIONS_DEFINE=	DOCS

CLIENT_DESC=	Build client
CLIENT_USES=		gl sdl xorg
CLIENT_USE=		GL=gl SDL=image2,mixer2,sdl2 XORG=x11
CLIENT_ALL_TARGET=	client
CLIENT_PLIST_FILES=	bin/sauer_client libexec/sauer_client
DEDICATED_DESC=	Build dedicated server
DEDICATED_ALL_TARGET=	server
DEDICATED_PLIST_FILES=	bin/sauer_server libexec/sauer_server
MASTER_DESC=	Build master server
MASTER_ALL_TARGET=	master

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
DESKTOP_ENTRIES="Sauerbraten" "${COMMENT}" \
			"${PREFIX}/share/${PORTNAME}/data/cube.png" "sauer_client" \
				"Game;" false
.endif

post-extract:
	@${FIND} ${WRKSRC} -type d -name CVS -type d -print0 | \
		${XARGS} -0 ${RM} -R

post-patch:
	@${REINPLACE_CMD}  '1d' ${WRKSRC}/src/enet/Makefile

do-install:
.for f in ${PLIST_FILES:Mbin/*}
	${INSTALL_SCRIPT} ${WRKDIR}/${f:T} ${STAGEDIR}${PREFIX}/${f}
.endfor
.for f in ${PLIST_FILES:Mlibexec/*}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${f:T} ${STAGEDIR}${PREFIX}/${f:H}
.endfor
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
