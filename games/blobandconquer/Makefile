# New ports collection makefile for:	blobandconquer
# Date created:		02 Apr 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	blobandconquer
DISTVERSION=	0.91-1
PORTREVISION=	1
CATEGORIES=	games
# original url: http://www.parallelrealities.co.uk/download.php?proj=blobAndConquer&file=${DISTNAME}&type=zip
MASTER_SITES=	http://www.amdmi3.ru/distfiles/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	blobAndConquer-${DISTVERSION}

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	A somewhat violent 3D action game

USE_SDL=	sdl mixer image ttf
USE_GL=		yes
USE_GMAKE=	yes
USE_DOS2UNIX=	makefile src/headers.h src/main.cpp
USE_GETTEXT=	yes

WRKSRC=		${WRKDIR}/blobAndConquer-${DISTVERSION:C/^([0-9]\.[0-9][0-9]).*/\1/}
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

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

.include <bsd.port.post.mk>
