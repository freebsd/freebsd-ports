# New ports collection makefile for:	gpstk
# Date created:				12 May 2004
# Whom:					bms@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gpstk
PORTVERSION=	1.5
CATEGORIES=	astro devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for developing GPS applications

BUILD_DEPENDS=	${LOCALBASE}/bin/jam:${PORTSDIR}/devel/jam

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

USE_PYTHON_RUN=	yes
USE_LDCONFIG=	yes

JAM=		${LOCALBASE}/bin/jam
JAM_ENV=	BINDIR="${PREFIX}/bin" \
		INCDIR="${PREFIX}/include/$(PORTNAME)" \
		LIBDIR="${PREFIX}/lib" \
		CC="${CC}" CCFLAGS="${CFLAGS}" \
		C++="${CXX}" C++FLAGS="${CXXFLAGS}" \
		OPTIM="-DHAVE_UINTPTR_T"

post-patch:
	@${REINPLACE_CMD} -e \
		's|python2.5|python|g' ${WRKSRC}/apps/reszilla/ordPlot

do-build:
	cd ${WRKSRC} && ${SETENV} ${JAM_ENV} ${JAM}

do-install:
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC} && ${SETENV} ${JAM_ENV} ${JAM} install
.for shlib in geomatics gpstk procframe rxio vplot
	@${LN} -sf lib${shlib}.so.15 ${PREFIX}/lib/lib${shlib}.so
.endfor
	@${STRIP_CMD} `${CAT} ${PLIST} | \
 		 ${GREP} '^bin/' | \
		 ${GREP} -E -v 'ddPlot$$|mdpscreen$$|ordPlot$$' | \
		 ${SED} 's:^bin/:${PREFIX}/bin/:g'`

.include <bsd.port.mk>
