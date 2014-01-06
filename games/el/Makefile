# Created by: Janni
# $FreeBSD$

PORTNAME=	el
PORTVERSION=	193
CATEGORIES=	games
MASTER_SITES=	LOCAL/rene \
		ftp://rene-ladan.nl/pub/distfiles/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Eternal Lands is a free 3D MMORPG

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libcal3d.so:${PORTSDIR}/graphics/cal3d
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/el.ini:${PORTSDIR}/games/el-data

USE_XZ=		yes
USES=		gmake openal:al,alut
USE_GNOME=	libxml2
USE_SDL=	sdl net image
USE_GL=		yes
LDFLAGS+=	-L${LOCALBASE}/lib -lX11

ALL_TARGET=	el.bin
MAKEFILE=	Makefile.bsd
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not build on ${ARCH}
.endif

pre-install:
	@${ECHO} "#!/bin/sh" > ${WRKDIR}/el
	@${ECHO} "cd ${DATADIR} || exit 1 " >> ${WRKDIR}/el
	@${ECHO} "exec ${DATADIR}/el.bin" >> ${WRKDIR}/el

	@${ECHO} "bin/el" > ${PLIST}
	@${ECHO} "%%DATADIR%%/el.bin" >> ${PLIST}
	@${ECHO} "@dirrmtry %%DATADIR%%" >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/el ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/el.bin ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
