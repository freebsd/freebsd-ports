# New ports collection makefile for:	flightgear
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=	FlightGear
PORTVERSION=	0.9.8
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Source/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Source/

MAINTAINER=	des@FreeBSD.org
COMMENT=	The FlightGear flight simulator

LIB_DEPENDS=	glut:${PORTSDIR}/graphics/libglut
BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${X11BASE}/include/simgear/threads/SGThread.hxx:${PORTSDIR}/devel/simgear \
		${X11BASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear
RUN_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${X11BASE}/include/simgear/threads/SGThread.hxx:${PORTSDIR}/devel/simgear \
		${X11BASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear \
		${LOCALBASE}/share/FlightGear/version:${PORTSDIR}/games/fgfs-base

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
# Force configure to look in ${LOCALBASE}/{include,lib}.  Note
# that it already knows about ${X11BASE}/{include,lib}.
# XXX Add ${PTHREAD_LIBS} to LDFLAGS to work around brokenness in
# XXX FreeBSD's gcc: libopenal is linked with -pthread and should
# XXX have a dependency on libpthread, but gcc ignores -pthread
# XXX when building shared objects.
CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--program-transform-name='s/^${CONFIGURE_TARGET}-//' \
		--datadir=${LOCALBASE}/share \
		--with-threads

MAN1=		est-epsilon.1 fgfs.1 fgjs.1 gl-info.1 js_demo.1 pstest.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

post-extract:
	@${FIND} ${WRKSRC} \( -name '.#*' -or -name '*~' \) -delete

do-install:
	@${ECHO} ">> Installing program"
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
