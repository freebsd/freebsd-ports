PORTNAME=	geographiclib
DISTVERSION=	2.2
CATEGORIES=	astro
MASTER_SITES=	SF/geographiclib/distrib-C%2B%2B \
		SF/geographiclib:geoids,gravity,magnetic
DISTNAME=	GeographicLib-${DISTVERSIONFULL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}	#
DIST_SUBDIR=	GeographicLib

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Library for geographic projections
WWW=		https://geographiclib.sourceforge.io/

LICENSE=	MIT
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.txt
LICENSE_FILE=	${LICENSE_FILE_MIT}

USES=		cmake compiler:c++11-lang localbase:ldflags pathfix
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DGEOGRAPHICLIB_DATA:STRING=${DATADIR:Q}
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_BOTH_LIBS \
		USE_BOOST_FOR_EXAMPLES \
		BUILD_MANPAGES
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS DOXYGEN EXAMPLES
OPTIONS_DEFAULT=	DOXYGEN PREC2
OPTIONS_GROUP=	DATASETS
OPTIONS_GROUP_DATASETS=	${_OPTIONS_GROUP_DATASETS}
OPTIONS_SINGLE=	PRECISION
OPTIONS_SINGLE_PRECISION=	PREC1 PREC2 PREC3 PREC4 PREC5
OPTIONS_SUB=	yes
DATASETS_DESC=	geoid datasets, gravity models and magnetic field models
PREC1_DESC=	1 = float
PREC2_DESC=	2 = double
PREC3_DESC=	3 = extended
PREC4_DESC=	4 = quadruple
PREC5_DESC=	5 = variable
PRECISION_DESC=	default "real" precision
DOCS_CMAKE_ON=	-DDOCDIR:STRING=${DOCSDIR:Q}
DOCS_CMAKE_OFF=	-DDOCDIR:STRING=NO
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CMAKE_BOOL=	BUILD_DOCUMENTATION
DOXYGEN_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen
EXAMPLES_CMAKE_ON=	-DEXAMPLEDIR:STRING=${EXAMPLESDIR:Q}
EXAMPLES_CMAKE_OFF=	-DEXAMPLEDIR:STRING=NO
PREC1_CMAKE_ON=	-DGEOGRAPHICLIB_PRECISION:STRING=1
PREC2_CMAKE_ON=	-DGEOGRAPHICLIB_PRECISION:STRING=2
PREC3_CMAKE_ON=	-DGEOGRAPHICLIB_PRECISION:STRING=3
PREC4_BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs
PREC4_RUN_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs
PREC4_USE=	GCC=yes
PREC4_CMAKE_ON=	-DGEOGRAPHICLIB_PRECISION:STRING=4
PREC5_BUILD_DEPENDS=	${LOCALBASE}/include/mpreal.h:math/mpfrc++
PREC5_LIB_DEPENDS=	libgmp.so:math/gmp \
			libmpfr.so:math/mpfr
PREC5_RUN_DEPENDS=	${LOCALBASE}/include/mpreal.h:math/mpfrc++
PREC5_CMAKE_ON=	-DGEOGRAPHICLIB_PRECISION:STRING=5
PREC5_VARS=	LICENSE+="GPLv3" LICENSE_COMB="multi"

GEOID_NAMES=		egm84-30 egm84-15 egm96-15 egm96-5\
			egm2008-5 egm2008-2_5 egm2008-1
GRAVITY_NAMES=		egm84 egm96 egm2008 wgs84 grs80
MAGNETIC_NAMES=		wmm2010 wmm2015 wmm2015v2 wmm2020\
			igrf11 igrf12 igrf13\
			emm2010 emm2015 emm2017
DEFAULT_GEOID_NAMES=	egm96-5
DEFAULT_GRAVITY_NAMES=	egm96 wgs84
DEFAULT_MAGNETIC_NAMES=	wmm2020 igrf13
DEPRECATED_NAMES=	wmm2015

.ifnmake portclippy
.for n in ${GEOID_NAMES}
GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=		Install ${n} geoid dataset\
	${"${DEPRECATED_NAMES:M${n}}"!="":?(deprecated):}
_OPTIONS_GROUP_DATASETS+=	GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}
GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	geoids-distrib/${n}.tar.bz2:geoids
ALL_DATASETS_OPTIONS+=	GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}
. if !empty(DEFAULT_GEOID_NAMES:M${n})
DEF_DATASETS_OPTIONS+=	GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}
. endif
.endfor
.for n in ${GRAVITY_NAMES}
GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=	Install ${n} gravity model\
	${"${DEPRECATED_NAMES:M${n}}"!="":?(deprecated):}
_OPTIONS_GROUP_DATASETS+=	GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}
GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	gravity-distrib/${n}.tar.bz2:gravity
ALL_DATASETS_OPTIONS+=	GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}
. if !empty(DEFAULT_GRAVITY_NAMES:M${n})
DEF_DATASETS_OPTIONS+=	GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}
. endif
.endfor
.for n in ${MAGNETIC_NAMES}
MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=	Install ${n} magnetic model\
	${"${DEPRECATED_NAMES:M${n}}"!="":?(deprecated):}
_OPTIONS_GROUP_DATASETS+=	MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}
MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	magnetic-distrib/${n}.tar.bz2:magnetic
ALL_DATASETS_OPTIONS+=	MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}
. if !empty(DEFAULT_MAGNETIC_NAMES:M${n})
DEF_DATASETS_OPTIONS+=	MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}
. endif
.endfor
.endif

# list of targets that require all distfiles
.ifmake makesum || makeplist || distclean
OPTIONS_DEFAULT+=	${ALL_DATASETS_OPTIONS}
# _OPTIONS_OK=yes to prevent recursive execution
_OPTIONS_OK=	yes
.else
OPTIONS_DEFAULT+=	${DEF_DATASETS_OPTIONS}
.endif

post-patch:
	${FIND} -- ${WRKSRC}/tools -name geographiclib-get-\*.sh \
		-exec ${REINPLACE_CMD} -e '/wget/s,wget -O,${FETCH_BINARY} -o ,' -- {} \;

.ifnmake portclippy
.for n in ${GEOID_NAMES}
post-install-GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}-on: install-datasets-geoids
.endfor
.for n in ${GRAVITY_NAMES}
post-install-GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}-on: install-datasets-gravity
.endfor
.for n in ${MAGNETIC_NAMES}
post-install-MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}-on: install-datasets-magnetic
.endfor

.for n in geoids gravity magnetic
install-datasets-${n}: .NOTMAIN
	${MKDIR} ${STAGEDIR}${DATADIR}/${n}
	(cd ${WRKDIR}/${n} &&\
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${n})
.PHONY: install-datasets-${n}
.endfor

x-tool-plist: .NOTMAIN .PHONY ${PLIST}
	${REINPLACE_CMD}\
		-e '/^%%PORTDOCS%%%%DOCSDIR%%/d'\
		-e '/^%%PORTEXAMPLES%%%%EXAMPLESDIR%%/d'\
		-e '/^%%DATADIR%%\/geoids\/[^.]/{\
		h;s|^%%DATADIR%%/geoids/\([^.]\{1,\}\).*|GEOID_\1|;\
		s/[^0-9A-Za-z]/_/g;\
		y/abcdefghijklmnopqrstuvwxyz/ABCDEFGHIJKLMNOPQRSTUVWXYZ/;\
		s/^/%%/;s/$$/%%/;G;s/\n//;}'\
		-e '/^%%DATADIR%%\/gravity\/[^.]/{\
		h;s|^%%DATADIR%%/gravity/\([^.]\{1,\}\).*|GRAVITY_\1|;\
		s/[^0-9A-Za-z]/_/g;\
		y/abcdefghijklmnopqrstuvwxyz/ABCDEFGHIJKLMNOPQRSTUVWXYZ/;\
		s/^/%%/;s/$$/%%/;G;s/\n//;}'\
		-e '/^%%DATADIR%%\/magnetic\/[^.]/{\
		h;s|^%%DATADIR%%/magnetic/\([^.]\{1,\}\).*|MAGNETIC_\1|;\
		s/[^0-9A-Za-z]/_/g;\
		y/abcdefghijklmnopqrstuvwxyz/ABCDEFGHIJKLMNOPQRSTUVWXYZ/;\
		s/^/%%/;s/$$/%%/;G;s/\n//;}'\
		${PLIST}
.endif

.include <bsd.port.mk>
