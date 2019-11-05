# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	dtcyber
PORTVERSION=	2.0b1
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://members.iinet.net.au/~tom-hunter/ \
		LOCAL/trasz
DISTNAME=	dtcyber20b1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop CYBER Emulator

USES=		dos2unix zip xorg
USE_XORG=	x11
NO_WRKSUBDIR=	yes
INSTALL_TARGET=
MAKEFILE=	Makefile.x11
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message
PLIST_FILES=	bin/dtcyber %%EXAMPLESDIR%%/cyber.ini %%EXAMPLESDIR%%/cos.tap

BROKEN_aarch64=		Fails to compile: error: Unable to determine size of basic data types
BROKEN_armv6=		Fails to compile: error: Unable to determine size of basic data types
BROKEN_armv7=		Fails to compile: error: Unable to determine size of basic data types
BROKEN_mips64=		Fails to compile: error: Unable to determine size of basic data types

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dtcyber ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cyber.ini ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Os/cos.tap ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
