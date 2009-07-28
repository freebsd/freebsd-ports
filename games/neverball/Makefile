# New ports collection makefile for:	neverball
# Date created:				26 October 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	neverball
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org:9090/neverball/ \
		http://offload2.icculus.org:9090/neverball/ \
		http://caffeinatedcontent.com/neverball/files/${PORTVERSION}/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tilt the floor to guide a ball through an obstacle course

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		vorbis.4:${PORTSDIR}/audio/libvorbis

USE_GL=		gl
USE_SDL=	ttf
USE_GMAKE=	yes
MAKE_ENV+=	ENABLE_WII=0
MAKE_JOBS_SAFE=	yes

PORTDOCS=	CHANGES COPYING README
MAN6=		neverball.6 neverputt.6

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
MAKE_ENV+=	ENABLE_NLS=1
LOCALE_DIRS=	ca de es fi fr lv nn
PLIST_SUB+=	NLS=""
.else
MAKE_ENV+=	ENABLE_NLS=0
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|./data|${DATADIR}/data|g ; \
		s|./locale|${PREFIX}/share/locale|g' \
			${WRKSRC}/share/base_config.h
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g ; \
		s| -O2| ${CFLAGS}|g ; s|%%LOCALBASE%%|${LOCALBASE}|g' \
			${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${DATADIR}/data
	@(cd ${WRKSRC}/data ; ${COPYTREE_SHARE} . ${DATADIR}/data/)
	@(cd ${WRKSRC}/dist ; ${INSTALL_MAN} ${MAN6} ${MAN1PREFIX}/man/man6/)
	@${MKDIR} ${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/pixmaps
.for f in neverball neverputt
	@${INSTALL_DATA} ${WRKSRC}/dist/${f}.desktop \
		${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/dist/${f}_512.png \
		${PREFIX}/share/pixmaps/${f}.png
	@${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin/
.endfor
.if !defined(WITHOUT_NLS)
.  for ii in ${LOCALE_DIRS}
	@${MKDIR} ${PREFIX}/share/locale/${ii}/LC_MESSAGES
	@${INSTALL_DATA} ${WRKSRC}/locale/${ii}/LC_MESSAGES/*.mo \
		${PREFIX}/share/locale/${ii}/LC_MESSAGES/
.  endfor
.endif

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.  for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
