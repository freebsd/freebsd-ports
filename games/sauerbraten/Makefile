# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	sauerbraten
PORTVERSION=	20130203
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2013_01_04
DISTNAME=	${PORTNAME}_2013_02_03_collect_edition_linux

MAINTAINER=	acm@FreeBSD.org
COMMENT=	First person shooter based on Cube

LICENSE=	MIT ZLIB
LICENSE_COMB=	multi

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ACLOCAL=true AUTOCONF=true AUTOMAKE=true
CONFIGURE_WRKSRC=	${WRKSRC}/src/enet
CONFIGURE_ARGS=	--enable-shared=no --enable-static=yes
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	libenet

PORTDATA=	data packages
PORTDOCS=	*
PLIST_DIRS=	%%DATADIR%%/packages/brush

OPTIONS_MULTI=	BUILD
OPTIONS_MULTI_BUILD=	CLIENT DEDICATED MASTER
OPTIONS_DEFAULT=	CLIENT DEDICATED

SUB_FILES=	pkg-message ${PLIST_FILES:Mbin/*:T}

OPTIONS_DEFINE=	DOCS

CLIENT_DESC=	Build client
CLIENT_USES=		gl xorg
CLIENT_USE=		GL=gl SDL=image,mixer,sdl XORG=x11
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
	@${REINPLACE_CMD} -Ee '/^#define (HAS_GETHOSTBY(NAME|ADDR)_R) 1/d' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

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
