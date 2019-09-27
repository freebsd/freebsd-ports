# Created by: Tatsuki Makino <tatsuki_makino@hotmail.com>
# $FreeBSD$

PORTNAME=	geographiclib
DISTVERSION=	1.50
CATEGORIES=	astro
MASTER_SITES=	SF/geographiclib/distrib\
		SF/geographiclib/distrib/archive\
		SF/geographiclib:geoids,gravity,magnetic
DISTNAME=	GeographicLib-${DISTVERSION}${DISTVERSIONSUFFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}	#
DIST_SUBDIR=	GeographicLib

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Library for geographic projections

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++14-lang python:env
WRKSRC=		${WRKDIR}/GeographicLib-${DISTVERSION}
PORTDOCS=	*
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DGEOGRAPHICLIB_DATA:STRING=${DATADIR:Q}\
		-DGEOGRAPHICLIB_LIB_TYPE:STRING=BOTH\
		-DINSTALL_PYTHON_DIR:STRING=${PYTHON_SITELIBDIR:Q}\
		-DINSTALL_DOC_DIR:STRING=${DOCSDIR:Q}

OPTIONS_DEFINE=	DOCS DOXYGEN PERL
OPTIONS_DEFAULT=	DOXYGEN PERL\
			GEOID_EGM96_5 GRAVITY_EGM96 GRAVITY_WGS84\
			MAGNETIC_WMM2015V2 MAGNETIC_IGRF12
PERL_DESC=	Build documentation with pod2man and pod2html
OPTIONS_GROUP=	DATASETS
OPTIONS_SUB=	yes
DOXYGEN_CMAKE_BOOL=	GEOGRAPHICLIB_DOCUMENTATION
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen\
			sphinx-build:textproc/py-sphinx
PERL_CMAKE_BOOL_OFF=	GEOGRAPHICLIB_NO_PERL
PERL_USE=	PERL5=build
PERL_USES=	perl5
PERL_BUILD_DEPENDS=	nroff:textproc/groff

GEOID_NAMES=		egm84-30 egm84-15 egm96-15 egm96-5\
			egm2008-5 egm2008-2_5 egm2008-1
GRAVITY_NAMES=		egm84 egm96 egm2008 wgs84 grs80
MAGNETIC_NAMES=		wmm2010 wmm2015 wmm2015v2 igrf11 igrf12\
			emm2010 emm2015 emm2017
DEPRECATED_NAMES=	wmm2015

.for n in ${GEOID_NAMES}
GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=		Install ${n} geoid dataset\
	${"${DEPRECATED_NAMES:M${n}}"!="":?(deprecated):}
OPTIONS_GROUP_DATASETS+=	GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}
GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	geoids-distrib/${n}.tar.bz2:geoids
MAKESUM_OPTIONS_DEFAULT+=	GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}
.endfor
.for n in ${GRAVITY_NAMES}
GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=	Install ${n} gravity model\
	${"${DEPRECATED_NAMES:M${n}}"!="":?(deprecated):}
OPTIONS_GROUP_DATASETS+=	GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}
GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	gravity-distrib/${n}.tar.bz2:gravity
MAKESUM_OPTIONS_DEFAULT+=	GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}
.endfor
.for n in ${MAGNETIC_NAMES}
MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=	Install ${n} magnetic model\
	${"${DEPRECATED_NAMES:M${n}}"!="":?(deprecated):}
OPTIONS_GROUP_DATASETS+=	MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}
MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	magnetic-distrib/${n}.tar.bz2:magnetic
MAKESUM_OPTIONS_DEFAULT+=	MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}
.endfor

# Memorandum: use "make fetch makesum" to makesum all distfiles.
.ifmake makesum || distclean
OPTIONS_DEFAULT=	${MAKESUM_OPTIONS_DEFAULT}
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

.PHONY: x-tool-plist
x-tool-plist: ${PLIST} .NOTMAIN
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
