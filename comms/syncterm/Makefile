# Created by: shurd
# $FreeBSD$

PORTNAME=	syncterm
PORTVERSION=	0.9.${PORTVER}
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.9.4
DISTNAME=	syncterm-src-${PORTVER}
EXTRACT_SUFX=	.tgz

MAINTAINER=	shurd@sasktel.net
COMMENT=	ANSI-BBS terminal which supports telnet, rlogin, and SSH

WRKSRC=		${WRKDIR}/syncterm-${PORTVER}
USES=		gmake
MAKEFILE=	GNUmakefile
PORTVER=	20110320
MAN1=		syncterm.1
MANCOMPRESSED=	yes

OPTIONS_DEFINE=	X11 SDL DEBUG
OPTIONS_DEFAULT=	X11 SDL

NO_STAGE=	yes
.include <bsd.port.options.mk>

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	does not configure except on i386 amd64

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
 LIB_DEPENDS+=	libcl.so:${PORTSDIR}/security/cryptlib
.else
 MAKE_ARGS+=	WITHOUT_CRYPTLIB=yes
.endif
MAKE_ARGS+=	WITHOUT_PORTAUDIO=yes
MAKE_ARGS+=	-C syncterm
MAKE_ARGS+=	PREFIX="${PREFIX}"
MAKE_ARGS+=	INSTALL_EXE="${INSTALL_PROGRAM}"
.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11
.else
MAKE_ARGS+=	NO_X=1
.endif
.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
MAKE_ARGS+=	USE_SDL=1
.endif
.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=	DEBUG=1
.else
MAKE_ARGS+=	RELEASE=1
.endif

.include <bsd.port.mk>
