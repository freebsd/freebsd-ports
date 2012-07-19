# New ports collection makefile for:	Nexuiz
# Date created:				03 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xonotic
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://hagger.rbi.informatik.uni-frankfurt.de/xonotic/ \
		http://dl.xonotic.org/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A fast-paced, chaotic, and intense multiplayer first person shooter

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

MANUAL_PACKAGE_BUILD=	huge

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/Xonotic/source/darkplaces
MAKEFILE=	BSDmakefile
MAKE_ARGS=	DP_FS_BASEDIR="${DATADIR}" \
		DP_PRELOAD_DEPENDENCIES=yes \
		CFLAGS_LIBJPEG="-I${LOCALBASE}/include -DLINK_TO_LIBJPEG" \
		OPTIM_RELEASE="${CFLAGS} -fno-strict-aliasing -funroll-loops" \
		STRIP="${STRIP_CMD}"
MAKE_JOBS_UNSAFE=yes
ALL_TARGET=	#
BINARIES=	#

OPTIONS=	CLIENT		"Build SDL client"		on \
		SERVER		"Build dedicated server"	on

.include <bsd.port.pre.mk>

.if !(defined(WITH_CLIENT) || defined(WITH_SERVER))
IGNORE=		requires at least one of CLIENT or SERVER options
.endif

.if !defined(WITHOUT_CLIENT)
LIB_DEPENDS+=	modplug.1:${PORTSDIR}/audio/libmodplug \
		theora.0:${PORTSDIR}/multimedia/libtheora \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		ogg:${PORTSDIR}/audio/libogg
USE_SDL=	sdl
ALL_TARGET+=	sdl-release
BINARIES+=	xonotic-sdl
.endif

.if !defined(WITHOUT_SERVER)
ALL_TARGET+=	sv-release
BINARIES+=	xonotic-dedicated
.endif

.for f in ${BINARIES}
PLIST_FILES+=	bin/${f}
.endfor

PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' \
		${WRKSRC}/${MAKEFILE} ${WRKSRC}/makefile.inc
	@${REINPLACE_CMD} -e '/LDFLAGS_BSDSV/s,$$,-L${LOCALBASE}/lib,' \
		${WRKSRC}/makefile.inc
	@${ECHO_CMD} >> ${WRKSRC}/prvm_offsets.h # silence 'no newline' warnings

do-install:
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f:C/xonotic/darkplaces/} ${PREFIX}/bin/${f}
.endfor
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}/data
	${INSTALL_DATA} ${WRKDIR}/Xonotic/data/*.pk3 ${DATADIR}/data/
.if !defined(WITHOUT_SERVER)
	cd ${WRKDIR}/Xonotic && ${COPYTREE_SHARE} server ${DATADIR}
# Fixup lost +x permissions on scripts after COPYTREE_SHARE
	${FIND} ${DATADIR}/server -type f -name *.sh -o -name rcon*.pl | \
		${XARGS} ${CHMOD} +x
.endif
.endif

.include <bsd.port.post.mk>
