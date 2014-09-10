# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	sauerbraten
PORTVERSION=	20130203
PORTREVISION=	1
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

OPTIONS_MULTI=	BUILD
OPTIONS_MULTI_BUILD=	CLIENT DEDICATED MASTER
OPTIONS_DEFAULT=	CLIENT DEDICATED
CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server
MASTER_DESC=	Build master server

SUB_FILES=	sauer_client sauer_master sauer_server pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
USE_GL=		yes
USE_SDL=	image mixer sdl
ALL_TARGET+=	client
SAUER_BIN+=	client

DESKTOP_ENTRIES="Sauerbraten" "${COMMENT}" \
			"${PREFIX}/share/${PORTNAME}/data/cube.png" "sauer_client" \
				"Game;" false
.endif

.if ${PORT_OPTIONS:MDEDICATED}
ALL_TARGET+=	server
SAUER_BIN+=	server
.endif

.if ${PORT_OPTIONS:MMASTER}
ALL_TARGET+=	master
SAUER_BIN+=	master
.endif

post-extract:
	@${FIND} ${WRKSRC} -type d -name CVS -type d -print0 | \
		${XARGS} -0 ${RM} -R

post-patch:
	@${REINPLACE_CMD} -Ee '/^#define (HAS_GETHOSTBY(NAME|ADDR)_R) 1/d' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
.for f in ${SAUER_BIN}
	${INSTALL_SCRIPT} ${WRKDIR}/sauer_${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/sauer_${f} ${STAGEDIR}${PREFIX}/libexec
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install:
.for f in ${SAUER_BIN}
	@${ECHO_CMD} bin/sauer_${f} >> ${TMPPLIST}
	@${ECHO_CMD} libexec/sauer_${f} >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>
