# $FreeBSD$

PORTNAME=	clthreads
DISTVERSION=	2.4.0
CATEGORIES=	devel
MASTER_SITES=	http://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ wrapper library around the POSIX threads API

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bz2
USE_LDCONFIG=	yes

PLIST_FILES=	include/clthreads.h \
		lib/libclthreads.so \
		lib/libclthreads.so.${DISTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libclthreads.so.${DISTVERSION}

.include <bsd.port.mk>
