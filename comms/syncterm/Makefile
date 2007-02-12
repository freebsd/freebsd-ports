# New ports collection makefile for:	syncterm
# Date created:		3 October 2006
# Whom:			shurd
#
# $FreeBSD$
#

PORTNAME=	syncterm
PORTVERSION=	0.8.20061020
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	syncterm-src-20061020
EXTRACT_SUFX=	.tgz

MAINTAINER=	shurd@sasktel.net
COMMENT=	An ANSI-BBS terminal which supports telnet, rlogin, and SSH

LIB_DEPENDS=	cl:${PORTSDIR}/security/cryptlib

WRKSRC=		${WRKDIR}/syncterm-20061020
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

OPTIONS=	X11	"Build with X11 support"	ON \
		SDL	"Build with SDL support"	ON \
		DEBUG	"Build a debug version"		OFF

PLIST_FILES=	bin/syncterm

.include <bsd.port.pre.mk>

MAKE_ARGS+=	-C syncterm
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ARGS+=	"INSTALL_EXE=${INSTALL_PROGRAM}"
.if defined(WITHOUT_X11)
MAKE_ARGS+=	NO_X=1
.else
USE_XLIB=	yes
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
