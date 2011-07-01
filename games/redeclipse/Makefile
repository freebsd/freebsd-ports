# New ports collection makefile for:	sauerbraten
# Date created:		2006-02-01
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	redeclipse
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_linux

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A single-player and multi-player first-person ego-shooter

LICENSE_COMB=	multi
LICENSE=	MIT ZLIB
LICENSE_NAME_ZLIB=	zlib license
LICENSE_FILE_ZLIB=	${WRKSRC}/license.txt
LICENSE_PERMS_ZLIB=	${_LICENSE_PERMS_DEFAULT}
LICENSE_GROUPS_ZLIB=	FSF GPL OSI

MANUAL_PACKAGE_BUILD=	huge

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/src/enet
CONFIGURE_ARGS=	--enable-shared=no --enable-static=yes
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	libenet ${BINARIES}
MAKE_JOBS_SAFE=	yes

SUB_FILES=	reclient reserver

PORTDATA=	*

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		OPTIMIZED_CFLAGS "Enabled additional optimizations" on

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not build on sparc64
.endif

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED)
IGNORE=		needs at least one executable (CLIENT or DEDICATED)
.endif

.if !defined(WITHOUT_CLIENT)
USE_GL=		yes
USE_SDL=	image mixer sdl
PLIST_FILES+=	bin/reclient libexec/reclient share/pixmaps/redeclipse.ico
BINARIES+=	client

DESKTOP_ENTRIES="Red Eclipse" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/redeclipse.ico" \
		"reclient" \
		"Application;Game;" \
		${FALSE}
.endif

.if !defined(WITHOUT_DEDICATED)
PLIST_FILES+=	bin/reserver libexec/reserver
BINARIES+=	server
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -fomit-frame-pointer
CXXFLAGS+=	-O3 -fomit-frame-pointer
.endif

do-install:
.for f in ${BINARIES}
	${INSTALL_SCRIPT} ${WRKDIR}/re${f} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/re${f} ${PREFIX}/libexec
.endfor
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} "." ${DATADIR}/
.endif
.if !defined(WITHOUT_CLIENT)
	${INSTALL_DATA} ${WRKSRC}/src/redeclipse.ico ${PREFIX}/share/pixmaps/
.endif

#post-install:
#	@${FIND} ${DATADIR} -type f | \
#		${SED} -e 's|^${PREFIX}/||' >> ${TMPPLIST}
#	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
#		${SED} -e 's|^${PREFIX}/|@dirrm |' >> ${TMPPLIST}

.include <bsd.port.mk>
