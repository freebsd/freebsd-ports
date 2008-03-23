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
PORTVER=	20070722
MAN1=		syncterm.1
MANCOMPRESSED=	yes

OPTIONS=	X11	"Build with X11 support"	on \
		SDL	"Build with SDL support"	on \
		DEBUG	"Build a debug version"		off

.include <bsd.port.pre.mk>

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
