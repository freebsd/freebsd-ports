# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>

PORTNAME=	alsa-seq-server
DISTVERSIONPREFIX=	v
PORTVERSION=		1.0.8
CATEGORIES=	audio

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	ALSA MIDI sequencer server

LICENSE=	BSD2CLAUSE

USES=		tar:bzip2 uidfix

USE_RC_SUBR=    alsa_seq_server

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky

PLIST_FILES=	sbin/alsa-seq-server \
		man/man8/alsa-seq-server.8.gz

OPTIONS_DEFINE=	DEBUG

MAKE_ARGS+=	HAVE_MAN="YES"
MAKE_ARGS+=	PTHREAD_LIBS="-lpthread"

DEBUG_MAKE_ARGS=	HAVE_DEBUG="YES"

.include <bsd.port.mk>
