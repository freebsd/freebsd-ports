# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gpstk
PORTVERSION=	2.0
CATEGORIES=	astro devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for developing GPS applications

LICENSE=	LGPL21

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam

USES=		dos2unix
USE_PYTHON_RUN=	yes
USE_LDCONFIG=	yes
DOS2UNIX_FILES=	${WRKSRC}/Jamrules

WRKSRC=		${WRKDIR}/${PORTNAME}

JAM=		jam
JAM_ENV=	PREFIX="${STAGEDIR}${PREFIX}" \
		CC="${CC}" CCFLAGS="${CFLAGS}" \
		C++="${CXX}" C++FLAGS="${CXXFLAGS}"

post-patch:
# Unbreak with modern C++ compilers (notably, Clang)
	@${REINPLACE_CMD} -e 's,assignFrom(,this->&,' \
		${WRKSRC}/src/Vector.hpp ${WRKSRC}/src/Matrix.hpp
	@${REINPLACE_CMD} -e 's,matSliceCheck(,this->&,' \
		${WRKSRC}/src/Matrix.hpp
	@${REINPLACE_CMD} -e 's,addData(,this->&,' \
		${WRKSRC}/src/FileFilterFrame.hpp
	@${REINPLACE_CMD} -e 's,float,double,' \
		${WRKSRC}/apps/swrx/gpsSim.cpp
	@${REINPLACE_CMD} -e '/GPSEllipsoid gm/s,const ,,' \
		${WRKSRC}/apps/reszilla/ddGen.cpp

do-build:
	cd ${WRKSRC} && ${SETENV} ${JAM_ENV} ${JAM} ${_MAKE_JOBS}

NOSTRIPFILES=	ddPlot|ordPlot  # don't strip scripts
SHLIBS=		geodyn geomatics gpstk procframe rxio vdraw vplot
SHLIBVER=	${PORTVERSION:S/.//g}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC} && ${SETENV} ${JAM_ENV} ${JAM} install
.for shlib in ${SHLIBS}
	${LN} -sf lib${shlib}.so.${SHLIBVER} \
		${STAGEDIR}${PREFIX}/lib/lib${shlib}.so
.endfor
	@${STRIP_CMD} `${GREP} '^bin/' ${PLIST} | \
		 ${GREP} -E -v '^bin/(${NOSTRIPFILES})$$' | \
			 ${SED} 's,^,${STAGEDIR}${PREFIX}/,'`

.include <bsd.port.mk>
