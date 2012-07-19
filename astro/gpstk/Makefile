# New ports collection makefile for:	gpstk
# Date created:				12 May 2004
# Whom:					bms@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gpstk
PORTVERSION=	2.0
CATEGORIES=	astro devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	jhein@symmetricom.com
COMMENT=	Toolkit for developing GPS applications

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PYTHON_RUN=	yes
USE_LDCONFIG=	yes
USE_DOS2UNIX=	yes
USE_GCC=	4.2+
DOS2UNIX_REGEX=	${WRKSRC}/Jamrules

JAM=		jam
JAM_ENV=	PREFIX="${PREFIX}" \
		BINDIR="${PREFIX}/bin" \
		INCDIR="${PREFIX}/include/${PORTNAME}" \
		LIBDIR="${PREFIX}/lib" \
		CC="${CC}" CCFLAGS="${CFLAGS}" \
		C++="${CXX}" C++FLAGS="${CXXFLAGS}"

do-build:
	cd ${WRKSRC} && ${SETENV} ${JAM_ENV} ${JAM}

NOSTRIPFILES=	ddPlot|ordPlot  # don't strip scripts
SHLIBS=		geodyn geomatics gpstk procframe rxio vdraw vplot
SHLIBVER=	${PORTVERSION:C/\.//g}
do-install:
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC} && ${SETENV} ${JAM_ENV} ${JAM} install
.for shlib in ${SHLIBS}
	@${LN} -sf lib${shlib}.so.${SHLIBVER} ${PREFIX}/lib/lib${shlib}.so
.endfor
	@${STRIP_CMD} `${GREP} '^bin/' ${PLIST} | \
		 ${GREP} -E -v '^bin/(${NOSTRIPFILES})$$' | \
		 ${SED} 's:^:${PREFIX}/:g'`

.include <bsd.port.mk>
