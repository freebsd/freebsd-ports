PORTNAME=	sndio
DISTVERSION=	1.10.0
CATEGORIES=	audio
MASTER_SITES=	https://sndio.org/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Small audio and MIDI framework from the OpenBSD project
WWW=		https://www.sndio.org/

LICENSE=	ISCL

USE_LDCONFIG=	yes
USE_RC_SUBR=	sndiod

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--default-dev="rsnd/default" \
		--prefix=${PREFIX} \
		--pkgconfdir=${PREFIX}/libdata/pkgconfig

# Parallel build leads to problems, but sndio is very quick to compile
# as is so not worth fixing
MAKE_JOBS_UNSAFE=	yes

USERS=		_sndio
GROUPS=		_sndio

post-patch:
# Make sure sndiod can be started inside jails as root
	@${REINPLACE_CMD} 's|err(1, "setpriority")|warn("setpriority")|' \
		${WRKSRC}/sndiod/sndiod.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsndio.so.7.3

.include <bsd.port.mk>
