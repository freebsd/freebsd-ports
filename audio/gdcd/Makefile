# New ports collection makefile for:	gdcd
# Date created:				Sat 3 June 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	gdcd
PORTVERSION=	0.0.2
CATEGORIES=	audio
MASTER_SITES=	http://cdcd.undergrid.net/gdcd/source_archive/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		cdaudio.1:${PORTSDIR}/audio/libcdaudio \
		Imlib.5:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

# for libcdaudio
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

post-install:
	@${ECHO}
	@${ECHO} "Don't forget to make a symlink from your CDROM device to /dev/cdrom!"
	@${ECHO}

.include <bsd.port.mk>
