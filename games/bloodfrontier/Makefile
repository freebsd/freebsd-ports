# New ports collection makefile for:	sauerbraten
# Date created:		2006-02-01
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	sauerbraten
PORTVERSION=	20060426
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sauerbraten
DISTNAME=	${PORTNAME}_2006_04_26_occlusion_edition_linux

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	First person shooter based on Cube

USE_X_PREFIX=	yes
USE_GL=		yes
USE_SDL=	sdl image mixer
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259 aclocal:19 automake:19
GNU_CONFIGURE=	yes
AUTOMAKE_ARGS=	-a -c --foreign --add-missing
CONFIGURE_WRKSRC=	${WRKSRC}/src/enet
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=	${WRKDIR}/${PORTNAME}
SAUDATDIR=	packages data
SUB_FILES=	sauer_client sauer_server pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not build on 4.x
.endif

post-extract:
	@${FIND} ${WRKSRC} -type d -name CVS -type d -print0 | ${XARGS} -0 ${RM} -R

post-patch:
	@${REINPLACE_CMD} -e 's|%%CXX%%|${CXX}|g ; \
		s|%%CXXFLAGS%%|${CXXFLAGS}|g ; s|%%X11BASE%%|${X11BASE}|g' \
			${WRKSRC}/src/Makefile

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/sauer_client ${WRKDIR}/sauer_server ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/sauer_client ${BUILD_WRKSRC}/sauer_server ${PREFIX}/libexec
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && \
		${FIND} -E ${SAUDATDIR} -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} -E ${SAUDATDIR} -type f -iregex ".*\.(png|cfg|jpg|ogg|ogz|txt|md2|ms3d|qc|wav)" \
			-exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && \
		${FIND} -E * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} -E * -type f -iregex ".*\.(html|css|jpg)" -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
