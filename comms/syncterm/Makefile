# New ports collection makefile for:	syncterm
# Date created:		3 October 2006
# Whom:			shurd
#
# $FreeBSD$
#

PORTNAME=	syncterm
PORTVERSION=	0.9.${PORTVER}
CATEGORIES=	comms
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.9
DISTNAME=	syncterm-src-${PORTVER}
EXTRACT_SUFX=	.tgz

MAINTAINER=	shurd@sasktel.net
COMMENT=	An ANSI-BBS terminal which supports telnet, rlogin, and SSH

WRKSRC=		${WRKDIR}/syncterm-${PORTVER}
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
PORTVER=	20080406
MAN1=		syncterm.1
MANCOMPRESSED=	yes

OPTIONS=	X11	"Build with X11 support"	on \
		SDL	"Build with SDL support"	on \
		DEBUG	"Build a debug version"		off

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
 LIB_DEPENDS+=	cl:${PORTSDIR}/security/cryptlib
.else
 MAKE_ARGS+=	WITHOUT_CRYPTLIB=yes
.endif
MAKE_ARGS+=	WITHOUT_PORTAUDIO=yes
MAKE_ARGS+=	-C syncterm
MAKE_ARGS+=	PREFIX="${PREFIX}"
MAKE_ARGS+=	INSTALL_EXE="${INSTALL_PROGRAM}"
.if !defined(WITHOUT_X11)
USE_XORG=	x11
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

.include <bsd.port.post.mk>
