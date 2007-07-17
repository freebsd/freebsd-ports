# New ports collection makefile for:	syncterm
# Date created:		3 October 2006
# Whom:			shurd
#
# $FreeBSD$
#

PORTNAME=	syncterm
PORTVERSION=	0.9.${PORTVER}
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	syncterm-src-${PORTVER}
EXTRACT_SUFX=	.tgz

MAINTAINER=	shurd@sasktel.net
COMMENT=	An ANSI-BBS terminal which supports telnet, rlogin, and SSH

LIB_DEPENDS=	cl:${PORTSDIR}/security/cryptlib

WRKSRC=		${WRKDIR}/syncterm-${PORTVER}
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
PORTVER=	20070704

OPTIONS=	X11	"Build with X11 support"	ON \
		SDL	"Build with SDL support"	ON \
		DEBUG	"Build a debug version"		OFF

.include <bsd.port.pre.mk>

MAKE_ARGS+=	-C syncterm
MAKE_ARGS+=	PREFIX="${PREFIX}"
MAKE_ARGS+=	INSTALL_EXE="${INSTALL_PROGRAM}"
.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.else
MAKE_ARGS+=	NO_X=1
.endif
.if !defined(WITHOUT_SDL)
USE_SDL=	sdl
MAKE_ARGS+=	USE_SDL=1
.endif
.if defined(WITH_DEBUG)
MAKE_ARGS+=	DEBUG=1
.else
MAKE_ARGS+=	RELEASE=1
.endif

do-install:
	${MKDIR} ${DESKTOPDIR}/
	${MKDIR} ${PREFIX}/share/icons/hicolor/64x64/apps/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/syncterm.png ${PREFIX}/share/icons/hicolor/64x64/apps/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/syncterm.desktop ${DESKTOPDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}/gcc.freebsd.exe.release/syncterm ${PREFIX}/bin/

.include <bsd.port.post.mk>
