# New ports collection makefile for:	mpck
# Date created:				25 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	mpck
PORTVERSION=	0.10
CATEGORIES=	audio
MASTER_SITES=	http://mpck.linuxonly.nl/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command-line utility for checking mp3 files for errors

GNU_CONFIGURE=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		mpck.1
PLIST_FILES=	bin/mpck

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/src/checkframe.c \
		${WRKSRC}/src/bufio.c

.include <bsd.port.mk>
