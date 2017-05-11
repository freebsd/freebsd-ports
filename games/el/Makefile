# Created by: Janni
# $FreeBSD$

PORTNAME=	el
PORTVERSION=	1.9.4.3
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	https://github.com/raduprv/Eternal-Lands/archive/
DISTFILES=	${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Eternal Lands is a free 3D MMORPG

LIB_DEPENDS=	libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libcal3d.so:graphics/cal3d
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/el.ini:games/el-data

BROKEN_sparc64=	Does not build on sparc64

USES=		compiler:c++11-lang gmake iconv openal:al,alut
USE_GNOME=	libxml2
USE_SDL=	sdl net image
USE_GL=		yes
USE_XORG=	x11
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB} -lX11

ALL_TARGET=	el.bin
MAKEFILE=	Makefile.bsd
WRKSRC=		${WRKDIR}/Eternal-Lands-${PORTVERSION}
PLIST_FILES=	bin/el \
		%%DATADIR%%/el.bin

pre-install:
	@${ECHO} "#!/bin/sh" > ${WRKDIR}/el
	@${ECHO} "cd ${DATADIR} || exit 1 " >> ${WRKDIR}/el
	@${ECHO} "exec ${DATADIR}/el.bin" >> ${WRKDIR}/el

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/el ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/el.bin ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
