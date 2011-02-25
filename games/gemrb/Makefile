# New ports collection makefile for:	gemrb
# Date created:			21 Apr 2008
# Whom:				Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	gemrb
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	games emulators
MASTER_SITES=	SF/${PORTNAME}/GemRB%20Sources/GemRB%20${PORTVERSION}%20Sources

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	GemRB (Game engine made with preRendered Background)

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		vorbis.4:${PORTSDIR}/audio/libvorbis

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_CMAKE=	yes
USE_SDL=	sdl mixer
USE_OPENAL=	al alut
USE_LDCONFIG=	yes
USE_PYTHON=	2.5+
CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include
CMAKE_C_FLAGS=	${CFLAGS}
CMAKE_ARGS=	-DDOC_DIR="${LOCALBASE}/share/doc/gemrb" -DMAN_DIR="${LOCALBASE}/man/man6" -DDISABLE_WERROR=1

MAN6=	gemrb.6

.include <bsd.port.pre.mk>

post-patch:
.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-noportdocs-*
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/gemrb.cfg ]; then \
		${CP} ${WRKSRC}/gemrb/GemRB.cfg.sample ${PREFIX}/etc/gemrb.cfg; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
