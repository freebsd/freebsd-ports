PORTNAME=	alsa-seq-server
DISTVERSIONPREFIX=	v
PORTVERSION=		1.1.0
PORTREVISION=		2
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ALSA MIDI sequencer server
WWW=		https://github.com/hselasky/alsa-seq-server

LICENSE=	BSD2CLAUSE

USES=		tar:bzip2 uidfix

USE_RC_SUBR=    alsa_seq_server

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky

PLIST_FILES=	sbin/alsa-seq-server \
		share/man/man8/alsa-seq-server.8.gz

OPTIONS_DEFINE=	DEBUG

MAKE_ARGS+=	HAVE_MAN="YES"
MAKE_ARGS+=	PTHREAD_LIBS="-lpthread"

DEBUG_MAKE_ARGS=	HAVE_DEBUG="YES"

post-patch:
	${REINPLACE_CMD} -e 's|$${PREFIX}/man/man|$${PREFIX}/share/man/man|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
