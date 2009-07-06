# New ports collection makefile for:	bfm
# Date created:				2007-02-26
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	bfm
PORTVERSION=	0.0.6.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/battle4mandicor
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Battle for Mandicor is free RTS fantasy game using Stratagus

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		vorbisfile.6:${PORTSDIR}/audio/libvorbis

USE_GMAKE=	yes
USE_LUA=	5.0
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LUA_INCDIR}" LDFLAGS="-L${LUA_LIBDIR}"

PORTSCOUT=	limit:(\d\.){2,}

post-extract:
	@${FIND} ${WRKSRC}/data -type d -name CVS -print0 | \
		${XARGS} -0 ${RM} -rf

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||; s|gcc|${CC}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-build:
	@(${ECHO_CMD} "#!${SH}"; \
	  ${ECHO_CMD} 'exec ${PREFIX}/libexec/bfm -d ${DATADIR} "$$@"') \
	  > ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/libexec
	cd ${WRKSRC}/data && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc-bfm/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
