PORTNAME=	geographiclib
DISTVERSION=	1.52
CATEGORIES=	astro
MASTER_SITES=	SF/geographiclib/distrib \
		SF/geographiclib/distrib/archive \
		SF/geographiclib:geoids,gravity,magnetic
DISTNAME=	GeographicLib-${DISTVERSIONFULL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}	#
DIST_SUBDIR=	GeographicLib

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Library for geographic projections

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++14-lang localbase python:env
USE_LDCONFIG=	yes
USE_PYTHON=	optsuffix
CMAKE_ARGS=	-DGEOGRAPHICLIB_DATA:STRING=${DATADIR:Q} \
		-DGEOGRAPHICLIB_LIB_TYPE:STRING=BOTH \
		-DINSTALL_PYTHON_DIR:STRING=${PYTHON_SITELIBDIR:Q} \
		-DINSTALL_DOC_DIR:STRING=${DOCSDIR:Q}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS DOXYGEN PERL
OPTIONS_DEFAULT=	DOXYGEN PERL PREC2
OPTIONS_GROUP=	DATASETS
OPTIONS_SINGLE=	PRECISION
OPTIONS_SINGLE_PRECISION=	PREC1 PREC2 PREC3 PREC4 PREC5
OPTIONS_SUB=	yes
DATASETS_DESC=	geoid datasets, gravity models and magnetic field models
PERL_DESC=	Build documentation with pod2man and pod2html
PREC1_DESC=	1 = float
PREC2_DESC=	2 = double
PREC3_DESC=	3 = extended
PREC4_DESC=	4 = quadruple
PREC5_DESC=	5 = variable
PRECISION_DESC=	default "real" precision
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR}
DOXYGEN_CMAKE_BOOL=	GEOGRAPHICLIB_DOCUMENTATION
PERL_BUILD_DEPENDS=	nroff:textproc/groff
PERL_USES=	perl5
PERL_USE=	PERL5=build
PERL_CMAKE_BOOL_OFF=	GEOGRAPHICLIB_NO_PERL
PREC1_CMAKE_ON=	-DGEOGRAPHICLIB_PRECISION:STRING=1
PREC2_CMAKE_ON=	-DGEOGRAPHICLIB_PRECISION:STRING=2
PREC3_CMAKE_ON=	-DGEOGRAPHICLIB_PRECISION:STRING=3
PREC4_BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs
PREC4_RUN_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs
PREC4_USE=	GCC=yes
PREC4_CMAKE_ON=	-DGEOGRAPHICLIB_PRECISION:STRING=4
PREC5_BROKEN=	error: call of overloaded 'max' is ambiguous\
		error: '*' was not declared in this scope
PREC5_BUILD_DEPENDS=	${LOCALBASE}/include/mpreal.h:math/mpfrc++
PREC5_LIB_DEPENDS=	libgmp.so:math/gmp \
			libmpfr.so:math/mpfr
PREC5_RUN_DEPENDS=	${LOCALBASE}/include/mpreal.h:math/mpfrc++
PREC5_USE=	GCC=yes
PREC5_CMAKE_ON=	-DGEOGRAPHICLIB_PRECISION:STRING=5

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

.for n in ${GEOID_NAMES}
GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=		Install ${n} geoid dataset\
	${"${DEPRECATED_NAMES:M${n}}"!="":?(deprecated):}
OPTIONS_GROUP_DATASETS+=	GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}
GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	geoids-distrib/${n}.tar.bz2:geoids
ALL_DATASETS_OPTIONS+=	GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}
. if !empty(DEFAULT_GEOID_NAMES:M${n})
DEF_DATASETS_OPTIONS+=	GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}
. endif
.endfor
.for n in ${GRAVITY_NAMES}
GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=	Install ${n} gravity model\
	${"${DEPRECATED_NAMES:M${n}}"!="":?(deprecated):}
OPTIONS_GROUP_DATASETS+=	GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}
GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	gravity-distrib/${n}.tar.bz2:gravity
ALL_DATASETS_OPTIONS+=	GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}
. if !empty(DEFAULT_GRAVITY_NAMES:M${n})
DEF_DATASETS_OPTIONS+=	GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}
. endif
.endfor
.for n in ${MAGNETIC_NAMES}
MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=	Install ${n} magnetic model\
	${"${DEPRECATED_NAMES:M${n}}"!="":?(deprecated):}
OPTIONS_GROUP_DATASETS+=	MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}
MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	magnetic-distrib/${n}.tar.bz2:magnetic
ALL_DATASETS_OPTIONS+=	MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}
. if !empty(DEFAULT_MAGNETIC_NAMES:M${n})
DEF_DATASETS_OPTIONS+=	MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}
. endif
.endfor

# list of targets that require all distfiles
.ifmake makesum || makeplist || distclean
OPTIONS_DEFAULT+=	${ALL_DATASETS_OPTIONS}
# _OPTIONS_OK=yes to prevent recursive execution
_OPTIONS_OK=	yes
.else
OPTIONS_DEFAULT+=	${DEF_DATASETS_OPTIONS}
.endif

post-patch:
	${REINPLACE_CMD} -e 's/\(tail\) --lines/\1 -n/g'\
		-e "s,head --lines -4,${SED} -e '\$$d' | ${SED} -e '\$$d' | ${SED} -e '\$$d' | ${SED} -e '\$$d',"\
		${WRKSRC}/man/makeusage.sh
	${REINPLACE_CMD} -e '/wget/s,wget -O,${FETCH_BINARY} -o ,'\
		${WRKSRC}/tools/geographiclib-get-*.sh

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
		-e '/^%%PORTDOCS%%/d'\
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

.include <bsd.port.mk>
