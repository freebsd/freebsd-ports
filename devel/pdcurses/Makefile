# New ports collection makefile for:	pdcurses
# Date created:				1 Jul 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	pdcurses
PORTVERSION=	3.4
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	PDCurses-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses library implementation for Win32, DOS, OS/2, and X11

CONFLICTS=	pdcurses-the-[0-9]*

USE_LDCONFIG=	yes
USE_XORG=	x11 xext sm ice xt xaw
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

OPTONS_DEFINE=	DEBUG LATIN1 NEXTAW XAW3D
LATIN1_DESC=	Enable support for Latin1 keys
NEXTAW_DESC=	Link with NeXtaw
XAW3D_DESC=	Link with Xaw3d

.include <bsd.port.options.mk>

.for opt in DEBUG LATIN1
.   if ${PORT_OPTIONS:M${opt}}
CONFIGURE_ARGS+=--enable-${opt:L}
.   endif
.endfor

.if ${PORT_OPTIONS:MNEXTAW}
LIB_DEPENDS+=	neXtaw.${XAWVER}:${PORTSDIR}/x11-toolkits/neXtaw
CONFIGURE_ARGS+=--with-nextaw
.endif

.if ${PORT_OPTIONS:MXAW3D}
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
CONFIGURE_ARGS+=--with-xaw3d
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(libdir)/$$(SHLPRE)$$(SHLFILE)$$(SHLPST)|&.2|' \
		${WRKSRC}/Makefile.in

post-install:
	@cd ${PREFIX}/lib && ${LN} -sf libXCurses.so.2 libXCurses.so

.include <bsd.port.mk>
