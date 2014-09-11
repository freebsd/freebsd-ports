# Created by: shurd
# $FreeBSD$

PORTNAME=	syncterm
PORTVERSION=	0.9.${PORTVER}
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.9.5
DISTNAME=	syncterm-src-${PORTVER}

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	ANSI-BBS terminal which supports telnet, rlogin, and SSH

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/syncterm-${PORTVER}/src/syncterm
USES=		gmake tar:tgz
MAKEFILE=	GNUmakefile
MAKE_ARGS+=	DONT_CLOBBER_CC=please
PORTVER=	20140603
INSTALLS_ICONS=	yes
PLIST_FILES=	bin/syncterm \
		man/man1/syncterm.1.gz \
		share/applications/syncterm.desktop \
		share/icons/hicolor/64x64/apps/syncterm.png

OPTIONS_DEFINE=	X11 SDL DEBUG
OPTIONS_DEFAULT=	X11 SDL

.include <bsd.port.options.mk>

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	does not configure except on i386 amd64

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
 LIB_DEPENDS+=	libcl.so:${PORTSDIR}/security/cryptlib
 MAKE_ARGS+=	CRYPTLIBINCLUDE=${LOCALBASE}/include
 MAKE_ARGS+=	CRYPTLIBDIR=${LOCALBASE}/lib
.else
 MAKE_ARGS+=	WITHOUT_CRYPTLIB=yes
.endif
MAKE_ARGS+=	WITHOUT_PORTAUDIO=yes
MAKE_ARGS+=	-C ${WRKSRC}
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

pre-build:
	if ( nm -D ${LOCALBASE}/lib/libcl.so | ${GREP} 'U __stack_chk_fail_local' ) then echo "LDFLAGS+=-fstack-protector" >> ${WRKSRC}/localdefs.mk ; fi

.include <bsd.port.mk>
