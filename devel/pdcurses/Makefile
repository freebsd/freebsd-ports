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
COMMENT=	Curses library implementation for Win32, DOS, OS/2 and X11

CONFLICTS=	pdcurses-the-[0-9]*

USE_LDCONFIG=	yes
USE_XORG=	x11 xext sm ice xt xaw
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

OPTIONS=	DEBUG "Enable debugging support" off \
		LATIN1 "Enable support for Latin1 keys" off \
		NEXTAW "Link with NeXtaw" off \
		XAW3D "Link with Xaw3d" off

.include <bsd.port.pre.mk>

.for opt in DEBUG LATIN1
.   if defined(WITH_${opt})
CONFIGURE_ARGS+=--enable-${opt:L}
.   endif
.endfor

.if defined(WITH_NEXTAW)
LIB_DEPENDS+=	neXtaw.${XAWVER}:${PORTSDIR}/x11-toolkits/neXtaw
CONFIGURE_ARGS+=--with-nextaw
.endif

.if defined(WITH_XAW3D)
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
CONFIGURE_ARGS+=--with-xaw3d
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(libdir)/$$(SHLPRE)$$(SHLFILE)$$(SHLPST)|&.2|' \
		${WRKSRC}/Makefile.in

post-install:
	@cd ${PREFIX}/lib && ${LN} -sf libXCurses.so.2 libXCurses.so

.include <bsd.port.post.mk>
