# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	a2png
PORTVERSION=	0.1.5
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts plain ASCII text into PNG bitmap images

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=	fails to build: parse.c:(.text+0x174): undefined reference to 'fgettok'
BROKEN_armv7=	fails to build: parse.c:(.text+0x174): undefined reference to 'fgettok'
BROKEN_i386=	fails to build: parse.c:(.text+0x135): undefined reference to 'fgettok'

LIB_DEPENDS=	libgd.so:graphics/gd

USES=		tar:bzip2 localbase
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gd --with-gdlib-config-path=${WRKDIR}
CFLAGS+=	-DDEFAULT_FONTPATH='\"${FONTROOTDIR}/TTF:${FONTROOTDIR}/Type1:${FONTROOTDIR}\"'
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

FONTROOTDIR?=	${LOCALBASE}/share/fonts

pre-configure:
	${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/gdlib-config
	${CHMOD} +x ${WRKDIR}/gdlib-config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
