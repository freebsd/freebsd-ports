# New ports collection makefile for:	flightgear
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=	FlightGear
PORTVERSION=	0.9.1
BASEVERSION=	0.9.1a
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Source/ \
		ftp://ftp.flightgear.org/pub/fgfs/Shared/
BASEFILE=	fgfs-base-${BASEVERSION}${EXTRACT_SUFX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${BASEFILE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	des@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${X11BASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
# Force configure to look in /usr/local/{include,lib}
CONFIGURE_ENV+=	CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		est-epsilon.1 fgfs.1 fgjs.1 gl-info.1 js_demo.1 pstest.1

pre-install:
	(cd ${PREFIX}/share && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
	    ${DISTDIR}/${BASEFILE} ${EXTRACT_AFTER_ARGS})
	(cd ${PREFIX}/share/${PORTNAME} && ${MV} data/* . && ${RMDIR} data)

.include <bsd.port.mk>
