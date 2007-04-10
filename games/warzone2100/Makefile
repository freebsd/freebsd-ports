# New ports collection makefile for:	warzone2100
# Date created:				21 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	warzone2100
PORTVERSION=	2.0.6
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/warzone/releases/2.0/

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Innovative 3D real-time strategy game

BUILD_DEPENDS=	bison>=2.1:${PORTSDIR}/devel/bison2 \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		mad.2:${PORTSDIR}/audio/libmad \
		ogg.5:${PORTSDIR}/audio/libogg \
		openal.0:${PORTSDIR}/audio/openal \
		physfs-1.0.1:${PORTSDIR}/devel/physfs \
		png.5:${PORTSDIR}/graphics/png \
		vorbis.3:${PORTSDIR}/audio/libvorbis

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_SDL=	net sdl
CONFIGURE_ARGS=	--program-transform-name=""
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|-m32||' ${WRKSRC}/configure
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -Ee 's|^(dist_doc_Data =) .*|\1|' \
		${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|AUTHORS||; s|COPYING COPYING\.README||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
