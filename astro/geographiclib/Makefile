# Created by: Tatsuki Makino <tatsuki_makino@hotmail.com>
# $FreeBSD$

PORTNAME=	geographiclib
PORTVERSION=	1.37
CATEGORIES=	astro
MASTER_SITES=	SF/geographiclib/distrib \
		SF/geographiclib:geoids,gravity,magnetic
DISTNAME=	GeographicLib-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	GeographicLib

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Library for geographic projections

LICENSE=	MIT

USES=		gmake libtool python
USE_GCC=	any
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
NO_WRKSUBDIR=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${DISTNAME}
MAKE_ARGS=	pythondir=${PYTHON_SITELIBDIR}/geographiclib
PORTDOCS=	*

OPTIONS_SUB=	yes
OPTIONS_DEFAULT=	GEOID_EGM96_5 GRAVITY_EGM96 GRAVITY_WGS84 \
			MAGNETIC_WMM2010 MAGNETIC_IGRF11

GEOID_NAMES:=		egm84-30 egm84-15 egm96-15 egm96-5 \
			egm2008-5 egm2008-2_5 egm2008-1
GRAVITY_NAMES:=		egm84 egm96 egm2008 wgs84
MAGNETIC_NAMES:=	wmm2010 igrf11 emm2010

.for n in ${GEOID_NAMES}
OPTIONS_DEFINE+=		GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}
GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=		Install ${n} geoid dataset
GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	geoids-distrib/${n}.tar.bz2:geoids
MAKESUM_DISTFILES+=		geoids-distrib/${n}.tar.bz2:geoids
MAKESUM_OPTIONS_DEFAULT+=	GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}
.endfor
.for n in ${GRAVITY_NAMES}
OPTIONS_DEFINE+=		GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}
GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=	Install ${n} gravity model
GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	gravity-distrib/${n}.tar.bz2:gravity
MAKESUM_DISTFILES+=		gravity-distrib/${n}.tar.bz2:gravity
MAKESUM_OPTIONS_DEFAULT+=	GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}
.endfor
.for n in ${MAGNETIC_NAMES}
OPTIONS_DEFINE+=		MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}
MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=	Install ${n} magnetic model
MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	magnetic-distrib/${n}.tar.bz2:magnetic
MAKESUM_DISTFILES+=		magnetic-distrib/${n}.tar.bz2:magnetic
MAKESUM_OPTIONS_DEFAULT+=	MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}
.endfor

# Memorandum: use "make fetch makesum" to makesum all distfiles.
.ifmake makesum || distclean
OPTIONS_DEFAULT=	${MAKESUM_OPTIONS_DEFAULT}
.endif

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e '/wget/s/wget -O/fetch -o /' \
		${WRKSRC}/tools/geographiclib-get-*.sh

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/geoids \
		${STAGEDIR}${DATADIR}/gravity \
		${STAGEDIR}${DATADIR}/magnetic
	${TOUCH} ${STAGEDIR}${DATADIR}/geoids/.keep \
		${STAGEDIR}${DATADIR}/gravity/.keep \
		${STAGEDIR}${DATADIR}/magnetic/.keep
.if ${PORT_OPTIONS:MGEOID_*}
	(cd ${WRKDIR}/geoids && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/geoids)
.endif
.if ${PORT_OPTIONS:MGRAVITY_*}
	(cd ${WRKDIR}/gravity && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/gravity)
.endif
.if ${PORT_OPTIONS:MMAGNETIC_*}
	(cd ${WRKDIR}/magnetic && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/magnetic)
.endif

.include <bsd.port.mk>
