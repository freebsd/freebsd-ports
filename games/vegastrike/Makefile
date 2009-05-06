# New ports collection makefile for:	vegastrike
# Date created:		05 May 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	vegastrike
PORTVERSION=	0.5.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	vegastrike-source-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Opensource 3D space simulator

RUN_DEPENDS=	${DATADIR}/vegastrike.ico:${PORTSDIR}/games/vegastrike-data
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		openal.0:${PORTSDIR}/audio/openal \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		ogg.5:${PORTSDIR}/audio/libogg

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_SDL=	sdl
USE_GL=		gl glu glut
USE_GNOME=	gtk20
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_JOBS_SAFE=	yes

# cegui and ffmpeg are not used yet
CONFIGURE_ARGS=	--disable-cegui --disable-ffmpeg \
		--with-data-dir="${LOCALBASE}/share/${PORTNAME}" \
		--enable-flags="${CXXFLAGS}"

PLIST_FILES=	bin/vegastrike bin/vssetup bin/vegaserver

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

OPTIONS=	MESHER "Enable mesher modelling tool" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MESHER)
CONFIGURE_ARGS+=	--disable-ogre
.else
PLIST_FILES+=	bin/mesher
BUILD_DEPENDS+=		${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d
RUN_DEPENDS+=		${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g; \
		s|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vegaserver ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vegastrike ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vssetup ${PREFIX}/bin
.if !defined(WITHOUT_MESHER)
	${INSTALL_PROGRAM} ${WRKSRC}/mesher ${PREFIX}/bin
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
