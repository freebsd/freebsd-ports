# New ports collection makefile for:	8kingdoms
# Date created:		2007-10-06
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	8kingdoms
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/kralovstvi/8%20Kingdoms/8%20Kingdoms%20${PORTVERSION}
DISTNAME=	${PORTNAME:S/k/K/}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	3D turn-based fantasy strategic game

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	sdl mixer
USE_TCL=	84
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST=		${WRKDIR}/pkg-plist
SUB_FILES=	pkg-message

post-extract:
	@${RM} -R ${WRKSRC}/doc/doxygen

post-patch:
	@${REINPLACE_CMD} -e 's|-ltcl8.4|-ltcl${TCL_VER:S/.//}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 1928d ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 16d ${WRKSRC}/common/da.h
	@${REINPLACE_CMD} -e 's|<tcl.h>|<tcl${TCL_VER}/tcl.h>|g' \
		${WRKSRC}/common/TCL/tcl_script.h

pre-install:
	@${RM} -f ${PLIST}
	@${ECHO_CMD} "bin/${PORTNAME}" >> ${PLIST}
	@cd ${WRKSRC}/res && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/res/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/res/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/res" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/doc && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%PORTDOCS%%%%DOCSDIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|%%PORTDOCS%%@dirrm %%DOCSDIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "%%PORTDOCS%%@dirrm %%DOCSDIR%%" >> ${PLIST}
.endif

do-install:
	@${MKDIR} ${DATADIR}/res
	@cd ${WRKSRC}/res && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/res/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/res/{}" \;
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME:S/k/K/} ${PREFIX}/bin/${PORTNAME}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && \
		${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.include <bsd.port.post.mk>
