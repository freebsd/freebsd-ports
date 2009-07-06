# New ports collection makefile for:	warzone2100
# Date created:				21 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	warzone2100
PORTVERSION=	2.0.10
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/warzone/releases/2.0/

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Innovative 3D real-time strategy game

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		mad.2:${PORTSDIR}/audio/libmad \
		ogg.6:${PORTSDIR}/audio/libogg \
		openal.0:${PORTSDIR}/audio/openal \
		physfs.1:${PORTSDIR}/devel/physfs \
		png.5:${PORTSDIR}/graphics/png \
		vorbis.4:${PORTSDIR}/audio/libvorbis

USE_BISON=	build
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_SDL=	net sdl
CONFIGURE_ARGS=	--program-transform-name="" --with-distributor="FreeBSD ports"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="${PTHREAD_LIBS}"
REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e 's|-m32||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|AUTHORS||; s|COPYING COPYING\.README||' \
		${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -Ee 's|install-dist_docDATA$$||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^install: install-am|install:|' \
		${WRKSRC}/doc/Makefile.in
.else
.endif

.include <bsd.port.mk>
