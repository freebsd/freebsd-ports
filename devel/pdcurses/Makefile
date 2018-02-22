# Created by: alepulver
# $FreeBSD$

PORTNAME=	pdcurses
DISTVERSION=	3.5
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	PDCurses-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses library implementation for Win32, DOS, OS/2, and X11

LICENSE=	PD

CONFLICTS=	pdcurses-the-[0-9]*

USE_LDCONFIG=	yes
USE_XORG=	x11 xext sm ice xt xaw xmu xpm
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

WRKSRC_SUBDIR=	x11

OPTIONS_DEFINE=	DEBUG LATIN1 NEXTAW XAW3D

DEBUG_CONFIGURE_ENABLE=	debug

LATIN1_DESC=		Latin1 keys support
LATIN1_CONFIGURE_ENABLE=latin1

NEXTAW_DESC=		Link with NeXtaw
NEXTAW_CONFIGURE_WITH=	nextaw
NEXTAW_LIB_DEPENDS=	libneXtaw.so:x11-toolkits/neXtaw

XAW3D_DESC=		Link with Xaw3d
XAW3D_CONFIGURE_WITH=	xaw3d
XAW3D_LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d

MAKE_ARGS=		libdir=${STAGEDIR}${PREFIX}/lib \
			bindir=${STAGEDIR}${PREFIX}/bin \
			includedir=${STAGEDIR}${PREFIX}/include \
			PDCURSES_SRCDIR=${WRKDIR}/${DISTNAME}

post-install:
	@cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libXCurses.so.2 libXCurses.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libXCurses.so.2

.include <bsd.port.mk>
