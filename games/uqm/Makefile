# Ports collection makefile for:   uqm
# Date created:        14 September 2003
# Whom:                asami
#
# $FreeBSD$
#

PORTNAME=      uqm
PORTVERSION=   0.3
CATEGORIES=    games
MASTER_SITES=  ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=sc2
DISTFILES=     ${PORTNAME}-${PORTVERSION}-source.tgz ${PORTNAME}-${PORTVERSION}-content.zip
EXTRACT_ONLY=  ${PORTNAME}-${PORTVERSION}-source.tgz

MAINTAINER=    benlutz@datacomm.ch
COMMENT=       A port of the original Star Control 2 for 3DO consoles

LIB_DEPENDS=   SDL_image:${PORTSDIR}/graphics/sdl_image \
	       SDL_mixer:${PORTSDIR}/audio/sdl_mixer \
	       vorbis:${PORTSDIR}/audio/libvorbis \
	       ogg:${PORTSDIR}/audio/libogg

USE_XLIB=      yes
USE_GMAKE=     yes
USE_SDL=       yes
NO_INSTALL_MANPAGES=yes

post-extract:
	${CP} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-content.zip ${WRKSRC}/content/packages/

do-configure:
	cd ${WRKSRC} && ${SETENV} LOCALBASE=${LOCALBASE} PREFIX=${PREFIX} ./build.sh uqm config

do-build:
	cd ${WRKSRC} && ./build.sh uqm

do-install:
	cd ${WRKSRC} && ./build.sh uqm install

post-install:
	${STRIP_CMD} ${PREFIX}/lib/uqm/uqm
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/users/manual.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
