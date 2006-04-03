# New ports collection makefile for:	blobandconquer
# Date created:		02 Apr 2006
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	blobandconquer
DISTVERSION=	0.1-1
CATEGORIES=	games
MASTER_SITES=	http://www.parallelrealities.co.uk/download.php?type=zip&file=
DISTNAME=	blobAndConquer-${DISTVERSION}

MAINTAINER=	amdmi3@mail.ru
COMMENT=	A somewhat violent 3D action game

FETCH_BEFORE_ARGS+=	-o ${DISTNAME}${EXTRACT_SUFX}

USE_X_PREFIX=	yes
USE_SDL=	sdl mixer image ttf
USE_GL=		yes
USE_GMAKE=	yes
USE_DOS2UNIX=	makefile src/headers.h src/main.cpp

WRKSRC=		${WRKDIR}/BlobAndConquer
PORTDOCS=	*

MAKEFILE=	makefile
MAKE_ENV=	CXX="${CXX}" DATADIR="${DATADIR}" DOCSDIR="${DOCSDIR}"

DESKTOP_ENTRIES="Blob and Conquer" \
		"Save Blobs" \
		"" \
		"blobAndConquer" \
		"Application;Game;" \
		false

post-patch:
	@${RM} -f ${WRKSRC}/doc/LICENSE
	@${FIND} ${WRKSRC} -type d -empty -exec ${TOUCH} "{}/.keep_me" \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/blobAndConquer ${PREFIX}/bin
.for d in data gfx music sound textures
	cd ${WRKSRC} && \
	${FIND} ${d} -type d -exec ${MKDIR} "${DATADIR}/{}" \; ;\
	${FIND} ${d} -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && \
	${FIND} . -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; ;\
	${FIND} . -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

.include <bsd.port.mk>
