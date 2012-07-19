# New ports collection makefile for:	gemrb
# Date created:			21 Apr 2008
# Whom:				Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	gemrb
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	games emulators
MASTER_SITES=	SF/${PORTNAME}/GemRB%20Sources/GemRB%20${PORTVERSION}%20Sources

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	GemRB (Game engine made with preRendered Background)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		vorbis:${PORTSDIR}/audio/libvorbis

USE_CMAKE=	yes
USE_SDL=	sdl mixer ttf
USE_OPENAL=	al alut
USE_LDCONFIG=	yes
USE_PYTHON=	2.6+
CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include
CMAKE_C_FLAGS=	${CFLAGS}
CMAKE_ARGS=	-DDOC_DIR="${DOCSDIR}" -DMAN_DIR="${MAN6PREFIX}/man/man6/" -DDISABLE_WERROR=1 -DINSOURCEBUILD=1

.include <bsd.port.pre.mk>

.if !defined(NO_INSTALL_MANPAGES)
MAN6=		gemrb.6
.endif

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
