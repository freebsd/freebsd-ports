# New ports collection makefile for:	portaudio
# Date created:		18 May 2003
# Whom:			michaelnottebrock@gmx.net and lioux@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	portaudio
PORTVERSION=	18.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/./_/}

MAINTAINER=	lofi@freebsd.org
COMMENT=	Portable cross-platform Audio API

USE_ZIP=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=yes

PLIST_SUB+=	SHLIB_VERSION=${SHLIB_VERSION}
SHLIB_VERSION=	0

pre-everything::
.if !defined(WITH_PATESTS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can additionally build portaudio's testsuite by defining WITH_PATESTS."
	@${ECHO_MSG}
PLIST_SUB+=	WITH_PATESTS="@comment "
.else
PLIST_SUB+=	WITH_PATESTS=""
.endif

pre-patch:
# replace \r\n with \n
	@${FIND} ${WRKSRC} -type f \
		| ${XARGS} -x -n 10 \
			${REINPLACE_CMD} -E \
				-e 's|||'
post-patch:
# replace obsolete headers, and fix up thread library
	@${FIND} ${WRKSRC} -type f \
		| ${XARGS} -x -n 10 \
			${REINPLACE_CMD} -E \
				-e 's|malloc.h|stdlib.h|' \
				-e 's|machine\/soundcard.h|sys\/soundcard.h|' \
				-e 's|-lpthread|${PTHREAD_LIBS}|'
pre-configure:
# Make configure executable
	@${CHMOD} +x ${WRKSRC}/configure

.if !defined(WITH_PATESTS)
post-configure:
	@${REINPLACE_CMD} -e 's|tests$$||' ${WRKSRC}/Makefile
.endif

post-install:
.if defined(WITH_PATESTS)
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin
.endif
	@${LN} -sf libportaudio.so \
		${PREFIX}/lib/libportaudio.so.${SHLIB_VERSION}

.include <bsd.port.mk>
