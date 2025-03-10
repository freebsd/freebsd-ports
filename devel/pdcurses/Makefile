PORTNAME=	pdcurses
DISTVERSION=	3.9
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	PDCurses-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses library implementation for Win32, DOS, OS/2, and X11
WWW=		http://pdcurses.sourceforge.net/

LICENSE=	PD

USES=		xorg
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
GNU_CONFIGURE=	yes

MAKE_ARGS=	bindir=${STAGEDIR}${PREFIX}/bin \
		includedir=${STAGEDIR}${PREFIX}/include \
		libdir=${STAGEDIR}${PREFIX}/lib \
		PDCURSES_SRCDIR=${WRKDIR}/${DISTNAME}
MAKE_JOBS_UNSAFE=	yes
LLD_UNSAFE=	yes # Needs linker to provide library search paths.

CONFLICTS=	pdcurses-the

WRKSRC_SUBDIR=	x11

OPTIONS_DEFINE=	DEBUG LATIN1 NEXTAW XAW3D

LATIN1_DESC=			Latin1 keys support
NEXTAW_DESC=			Link with NeXtaw
XAW3D_DESC=			Link with Xaw3d
DEBUG_CONFIGURE_ENABLE=		debug
LATIN1_CONFIGURE_ENABLE=	latin1
NEXTAW_LIB_DEPENDS=		libneXtaw.so:x11-toolkits/neXtaw
NEXTAW_CONFIGURE_WITH=		nextaw
XAW3D_LIB_DEPENDS=		libXaw3d.so:x11-toolkits/Xaw3d
XAW3D_CONFIGURE_WITH=		xaw3d

#post-install:
#	@cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libXCurses.so.2 libXCurses.so
#	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libXCurses.so.2

.include <bsd.port.mk>
