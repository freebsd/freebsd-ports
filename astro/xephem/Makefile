# New ports collection makefile for:    xephem
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xephem
PORTVERSION=	3.2.3
CATEGORIES=	astro
MASTER_SITES=	ftp://iraf.noao.edu/contrib/xephem/ \
		ftp://gastro23.physics.uiowa.edu/pub/xephem/ \
		ftp://iphcip1.physik.uni-mainz.de/pub/xephem/ \
		ftp://wolf.ifj.edu.pl/mirror/xephem/

MAINTAINER=	erich@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes
MANCOMPRESSED=	no
WRKSRC=		${WRKDIR}/${DISTNAME}/GUI/xephem

LIBSRC=		${WRKDIR}/${DISTNAME}/libastro

MAN1=		xephem.1

AUXIL=		README jupiter.9910 logo.gif mars.9910 mars_db marsmap.fts \
		moon.fts moon_db saturne.9910 uranus.9910 xephem.hlp \
		xephem_sites

CATALOGS=	ISS.edb Messier.edb NGC.edb README SAC.edb \
		YBS.edb asteroids.edb comets.edb hickson.edb

TOOLS=		README extract.awk astorb2edb.pl jost2edb.awk mpcorb2edb.pl \
		tle2edb.pl

GSC=		Makefile README gscload.c support.c

XEPHEMDBD=	INSTALL Makefile README cgi-lib.pl db.c fsfetch.c request.c \
		stubs.c xephemdbd.c xephemdbd.html xephemdbd.pl

pre-configure:
	@(cd ${LIBSRC} && ${XMKMF})

pre-build:
	@(cd ${LIBSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})
	${SED} -e "s^@PREFIX@^${PREFIX}^" ${WRKSRC}/XEphem.ad > ${WRKSRC}/XEphem.ad.new

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xephem ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xephem.man ${PREFIX}/man/man1/xephem.1
	${INSTALL_DATA} ${WRKSRC}/XEphem.ad.new ${PREFIX}/lib/X11/app-defaults/XEphem
	${MKDIR} ${PREFIX}/lib/X11/xephem

	${MKDIR} ${PREFIX}/lib/X11/xephem/auxil
.for file in ${AUXIL}
	${INSTALL_DATA} ${WRKSRC}/auxil/${file} ${PREFIX}/lib/X11/xephem/auxil/${file}
.endfor

	${MKDIR} ${PREFIX}/lib/X11/xephem/catalogs
.for file in ${CATALOGS}
	${INSTALL_DATA} ${WRKSRC}/catalogs/${file} ${PREFIX}/lib/X11/xephem/catalogs/${file}
.endfor

	${MKDIR} ${PREFIX}/lib/X11/xephem/tools
.for file in ${TOOLS}
	${INSTALL_DATA} ${WRKSRC}/tools/${file} ${PREFIX}/lib/X11/xephem/tools/${file}
.endfor

	${MKDIR} ${PREFIX}/lib/X11/xephem/tools/gsc
.for file in ${GSC}
	${INSTALL_DATA} ${WRKSRC}/tools/gsc/${file} ${PREFIX}/lib/X11/xephem/tools/gsc/${file}
.endfor

	${MKDIR} ${PREFIX}/lib/X11/xephem/tools/xephemdbd
.for file in ${XEPHEMDBD}
	${INSTALL_DATA} ${WRKSRC}/tools/xephemdbd/${file} ${PREFIX}/lib/X11/xephem/tools/xephemdbd/${file}
.endfor

.include <bsd.port.mk>
