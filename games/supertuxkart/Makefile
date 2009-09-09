# New ports collection makefile for:	supertuxkart
# Date created:		21 Mar 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	supertuxkart
PORTVERSION=	0.6.2
CATEGORIES=	games
MASTER_SITES=	SF/supertuxkart/SuperTuxKart/${PORTVERSION}
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Free 3D kart racing game

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut \
		vorbisfile.6:${PORTSDIR}/audio/libvorbis \
		ogg.6:${PORTSDIR}/audio/libogg

USE_BZIP2=	yes
USE_GL=		gl glu glut
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_SDL=	sdl
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*

# Using LIBS instead of LDFLAGS, otherwise will break when
# there's devel/bullet port installed
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CPPFLAGS="-I${LOCALBASE}/include"

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(datadir)/games|$$(datadir)|g; \
		 s|$$(prefix)/games|$$(prefix)/bin|g'
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-dist_pkgdataDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
