# New ports collection makefile for:	flightgear-atlas
# Date created:				16 Sep 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flightgear-atlas
PORTVERSION=	0.3.1.20090529
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://contribs.martymac.com/FreeBSD-ports/distfiles/ \
		http://freebsd.unixfreunde.de/sources/
DISTNAME=	Atlas-${PORTVERSION}

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	A map viewer for use with the FlightGear flight simulator

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/include/simgear/version.h:${PORTSDIR}/devel/simgear
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		curl.5:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/include/simgear/version.h:${PORTSDIR}/devel/simgear \
		${LOCALBASE}/share/FlightGear/version:${PORTSDIR}/games/flightgear-data

USE_AUTOTOOLS=	aclocal:19 autoheader:262 automake:15 autoconf:262
AUTOMAKE_ARGS=	--add-missing

GNU_CONFIGURE=	yes
USE_XORG=	ice sm x11 xext xi xt xmu
USE_GL=		gl glu glut

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS} \
		-DSG_GLUT_H='<GL/glut.h>' \
		-DSG_GL_H='<GL/gl.h>' \
		-DSTL_STRING='<string>'
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-fgbase="${LOCALBASE}/share/FlightGear"

post-patch:
	@${REINPLACE_CMD} -e 's|^base_LIBS="$$LIBS"|base_LIBS="$$LIBS ${PTHREAD_LIBS}"|' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|^AC_CHECK_LIB(pthread, pthread_exit)||' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|-lpthread||' ${WRKSRC}/src/Makefile.am

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/AtlasPalette ${LOCALBASE}/share/FlightGear
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
