# New ports collection makefile for:	formido
# Date created:				19 Nov 2005
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	formido
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://koti.mbnet.fi/lsoft/formido/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D kill-em all with 3D rendered graphics

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer image

HISCOREDIR=	/var/games/formido

CC=		${CXX}
MAKE_ENV=	DATDIR="${DATADIR}" HISCOREDIR="${HISCOREDIR}" \
		LINKFLAGS="${CXXFLAGS}" DEFAULT_CONFIG_FILE="${DATADIR}/formido.cfg"

OPTIONS=	MUSIC "Install music (6MB)" on

.include <bsd.port.pre.mk>

.ifdef(WITH_MUSIC)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-music${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
PLIST_SUB+=	MUSIC:=""
.else
PLIST_SUB+=	MUSIC:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|formido.cfg|.formido.cfg|g' ${WRKSRC}/src/*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/formido ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/* ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/formido.cfg ${DATADIR}
.ifdef(WITH_MUSIC)
	cd ${DATADIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${PORTNAME}-music${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}
	${CHOWN} root:wheel ${DATADIR}/*.ogg
	${CHMOD} 644 ${DATADIR}/*.ogg
.endif
	${CHGRP} games ${PREFIX}/bin/formido
	${CHMOD} g+s ${PREFIX}/bin/formido

post-install:
.if !exists(${HISCOREDIR})
	${MKDIR} ${HISCOREDIR}
	${CHGRP} games ${HISCOREDIR}
	${CHMOD} g+w ${HISCOREDIR}
.endif

.include <bsd.port.post.mk>
