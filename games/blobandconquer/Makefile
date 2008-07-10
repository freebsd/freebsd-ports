# New ports collection makefile for:	blobandconquer
# Date created:		02 Apr 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	blobandconquer
DISTVERSION=	0.98-1
CATEGORIES=	games
# original url: http://www.parallelrealities.co.uk/download.php?proj=blobAndConquer&file=${DISTNAME}&type=zip
MASTER_SITES=	http://www.amdmi3.ru/distfiles/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|amdmi3|} \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	blobAndConquer-${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A somewhat violent 3D action game

USE_SDL=	sdl mixer image ttf
USE_GL=		yes
USE_GMAKE=	yes
USE_DOS2UNIX=	makefile src/headers.h src/main.cpp
USE_GETTEXT=	yes
WANT_GNOME=	yes
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/blobAndConquer-${DISTVERSION:C/^([0-9]\.[0-9][0-9]).*/\1/}
PORTDOCS=	*

MAKEFILE=	makefile
MAKE_ENV=	CXX="${CXX}" DATADIR="${DATADIR}" DOCSDIR="${DOCSDIR}"

post-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} buildpak)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/blobAndConquer ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/blobAndConquer.pak ${DATADIR}/
	${MKDIR} ${PREFIX}/share/icons/hicolor/32x32/apps
	${INSTALL_DATA} ${WRKSRC}/icons/blobAndConquer.png \
		${PREFIX}/share/icons/hicolor/32x32/apps/
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/icons/blobAndConquer.desktop \
		${DESKTOPDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

.include <bsd.port.post.mk>
