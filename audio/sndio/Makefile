# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	sndio
PORTVERSION=	1.5.0
CATEGORIES=	audio
MASTER_SITES=	http://www.sndio.org/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Small audio and MIDI framework from the OpenBSD project

LICENSE=	ISCL

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${PREFIX}/man

USE_LDCONFIG=	yes
USE_RC_SUBR=	sndiod

USERS=		_sndio
GROUPS=		_sndio

# Parallel build leads to problems, but sndio is very quick to compile
# as is so not worth fixing
MAKE_JOBS_UNSAFE=	yes

post-patch:
# Make sure sndiod can be started inside jails as root
	@${REINPLACE_CMD} 's|err(1, "setpriority")|warn("setpriority")|' \
		${WRKSRC}/sndiod/sndiod.c

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/libsndio.so.6.1 \
		${STAGEDIR}${PREFIX}/bin/sndiod \
		${STAGEDIR}${PREFIX}/bin/aucat \
		${STAGEDIR}${PREFIX}/bin/midicat

.include <bsd.port.mk>
