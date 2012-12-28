# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pianobar
PORTVERSION=	2012.12.01
CATEGORIES=	audio
MASTER_SITES=	http://6xq.net/projects/${PORTNAME}/

MAINTAINER=	john@pcbsd.org
COMMENT=	Command line Pandora player

LICENSE=	MIT

LIB_DEPENDS=	ao:${PORTSDIR}/audio/libao \
		faad:${PORTSDIR}/audio/faad \
		mad:${PORTSDIR}/audio/libmad \
		gnutls:${PORTSDIR}/security/gnutls \
		json:${PORTSDIR}/devel/json-c \
		gcrypt:${PORTSDIR}/security/libgcrypt

MAN1=		pianobar.1
MAN_COMPRESSED=	no

PLIST_FILES=	bin/pianobar

USE_BZIP2=	yes
USE_GMAKE=	yes

CFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
