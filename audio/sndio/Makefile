# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	sndio
PORTVERSION=	1.7.0
CATEGORIES=	audio
MASTER_SITES=	https://sndio.org/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Small audio and MIDI framework from the OpenBSD project

LICENSE=	ISCL

USE_LDCONFIG=	yes
USE_RC_SUBR=	sndiod

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--default-dev="rsnd/default" \
		--prefix=${PREFIX}

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
	cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} \
		aucat midicat sndioctl sndiod
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsndio.so.7.1

.include <bsd.port.mk>
