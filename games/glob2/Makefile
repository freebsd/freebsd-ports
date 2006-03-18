# New ports collection makefile for:	glob2
# Date created:		Wed 21 apr 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		glob2
PORTVERSION=		0.8.19
CATEGORIES=		games
MASTER_SITES=		http://globulation2.org/releases/${PORTVERSION}/

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Globulation 2 - a free and innovative strategy game

BUILD_DEPENDS=		${LOCALBASE}/include/boost/rational.hpp:${PORTSDIR}/devel/boost
LIB_DEPENDS=		vorbis.3:${PORTSDIR}/audio/libvorbis	\
			speex.3:${PORTSDIR}/audio/speex		\
			freetype.9:${PORTSDIR}/print/freetype2

USE_SDL=		image net sdl ttf
USE_GL=			yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include"	\
			LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=			Does not compile with gcc-2.95
.endif

.if ${ARCH} == "alpha"
BROKEN=			Does not build on ${ARCH}
.endif

pre-configure:
	${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|"	\
		${WRKSRC}/configure
	${REINPLACE_CMD} -e "s|Icon=|Icon=${DATADIR}/|"		\
		${WRKSRC}/data/glob2.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/glob2 ${PREFIX}/bin
	${MKDIR} ${DATADIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/data/glob2.desktop ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/data/icons/glob2-icon-48x48.png ${DATADIR}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
