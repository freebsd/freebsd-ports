# New ports collection makefile for:	flightgear
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=	FlightGear
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Source/ \
		ftp://ftp.flightgear.org/pub/fgfs/Shared/

MAINTAINER=	des@FreeBSD.org
COMMENT=	The FlightGear flight simulator

BASEVERSION=	${PORTVERSION}
BASEFILE=	fgfs-base-${BASEVERSION}${EXTRACT_SUFX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${BASEFILE}

BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${X11BASE}/include/simgear/threads/SGThread.hxx:${PORTSDIR}/devel/simgear \
		${X11BASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear
RUN_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${X11BASE}/include/simgear/threads/SGThread.hxx:${PORTSDIR}/devel/simgear \
		${X11BASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
# Force configure to look in ${LOCALBASE}/{include,lib}
CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-threads

MAN1=		est-epsilon.1 fgfs.1 fgjs.1 gl-info.1 js_demo.1 pstest.1

post-extract:
	@${FIND} ${WRKSRC} \( -name '.#*' -or -name '*~' \) -print -delete

do-install:
	@${ECHO} ">> Installing program"
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
	@${ECHO} ">> Installing data"
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 0755 ${DATADIR}
	@(cd ${WRKSRC}/data && ${FIND} . -type d | (cd ${DATADIR} &&\
		${XARGS} ${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 0755))
	@(cd ${WRKSRC}/data && ${FIND} . -type f |\
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR})

.include <bsd.port.mk>
