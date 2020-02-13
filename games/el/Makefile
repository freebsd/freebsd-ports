# Created by: Janni
# $FreeBSD$

PORTNAME=	el
PORTVERSION=	1.9.5.6
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Eternal Lands is a free 3D MMORPG

BROKEN_sparc64=		fails to build on sparc64

LIB_DEPENDS=	libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libcal3d.so:graphics/cal3d
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/el.ini:games/el-data

USES=		compiler:c++11-lang gl gmake gnome iconv openal:al,alut sdl xorg
USE_GNOME=	libxml2
USE_SDL=	sdl2 net2 image2
USE_GL=		gl glu
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	raduprv
GH_PROJECT=	Eternal-Lands
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB} -lX11
LLD_UNSAFE=	yes

ALL_TARGET=	el.bin
MAKEFILE=	Makefile.bsd
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
