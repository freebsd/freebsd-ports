# New ports collection makefile for:	portaudio
# Date created:		18 May 2003
# Whom:			michaelnottebrock@gmx.net and lioux@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	portaudio
PORTVERSION=	18
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	michaelnottebrock@gmx.net
COMMENT=	Portable cross-platform Audio API

USE_REINPLACE=	yes
USE_ZIP=	yes
USE_GMAKE=	yes
MAKEFILE=	Makefile.linux
ALL_TARGET=	sharedlib
PLIST_SUB=	SHLIB_VERSION=${SHLIB_VERSION}
INSTALLS_SHLIB=	yes

SHLIB_VERSION=	0

post-patch:
# replace \r\n with \n
# replace <malloc.h> with <stdlib.h>
	@${FIND} ${WRKSRC} -type f \
		| ${XARGS} -x -n 10 \
			${REINPLACE_CMD} -E \
				-e 's|||' \
				-e 's|malloc.h|stdlib.h|' \
				-e 's|machine\/soundcard.h|sys\/soundcard.h|'

# C{C,FLAGS} and PREFIX safeness
	@${REINPLACE_CMD} -E \
		-e 's|gcc|${CC} ${CFLAGS}|' \
		-e 's|^CFLAGS.*$$||' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/pa_common/portaudio.h \
		${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/pa_unix_oss/libportaudio.so \
		${PREFIX}/lib
	@${LN} -sf libportaudio.so \
		${PREFIX}/lib/libportaudio.so.${SHLIB_VERSION}

.include <bsd.port.mk>
