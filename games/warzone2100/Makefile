# New ports collection makefile for:	warzone2100
# Date created:				21 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	warzone2100
DISTVERSION=	2.0.5_rc1
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/warzone/releases/2.0/

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Innovative 3D real-time strategy game

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		mad.2:${PORTSDIR}/audio/libmad \
		ogg.5:${PORTSDIR}/audio/libogg \
		openal.0:${PORTSDIR}/audio/openal \
		physfs-1.0.1:${PORTSDIR}/devel/physfs \
		png.5:${PORTSDIR}/graphics/png \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_BISON=	yes
USE_GL=		yes
USE_SDL=	net sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=""
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib
WRKSRC=		${WRKDIR}/warzone-${DISTVERSION}

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 5000000
	@${REINPLACE_CMD} -e 's|<stdint\.h>|<inttypes.h>|' \
		${WRKSRC}/lib/framework/types.h
.endif
	@${REINPLACE_CMD} -e \
		's|-m32||; \
		 s|/usr/local|${LOCALBASE}|; \
		 s|/usr/X11R6|${X11BASE}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
