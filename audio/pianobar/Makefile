# New ports collection makefile for: pianobar
# Date created: 8 October 2010
# Whom: John Hixson <john@pcbsd.org>
#
# $FreeBSD$
#

PORTNAME=	pianobar
PORTVERSION=	2012.06.24
CATEGORIES=	audio
MASTER_SITES=	http://6xq.net/projects/${PORTNAME}/

MAINTAINER=	john@pcbsd.org
COMMENT=	Command line Pandora player

LIB_DEPENDS=	ao:${PORTSDIR}/audio/libao \
		faad:${PORTSDIR}/audio/faad \
		mad:${PORTSDIR}/audio/libmad \
		gnutls.47:${PORTSDIR}/security/gnutls \
		json.0:${PORTSDIR}/devel/json-c \
		gcrypt:${PORTSDIR}/security/libgcrypt

LICENSE=	MIT

MAN1=		pianobar.1
MAN_COMPRESSED=	no

PLIST_FILES=	bin/pianobar

USE_BZIP2=	yes
USE_GMAKE=	yes

CFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
