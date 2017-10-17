# Created by: Tatsuki Makino <tatsuki_makino@hotmail.com>
# $FreeBSD$

PORTNAME=	geographiclib
PORTVERSION=	1.46
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	SF/geographiclib/distrib\
		SF/geographiclib:geoids,gravity,magnetic
DISTNAME=	GeographicLib-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	GeographicLib

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Library for geographic projections

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ax_check_compile_flag.m4:devel/autoconf-archive

USES=		autoreconf compiler:c++11-lang gmake libtool python
PORTDOCS=	*
FETCH_ENV+=	HTTP_REFERER=
GNU_CONFIGURE=	yes
MAKE_ARGS+=	geographiclib_data=${DATADIR:Q}
MAKE_ARGS+=	pythondir=${PYTHON_SITELIBDIR}/geographiclib
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOXYGEN PERL
OPTIONS_DEFAULT=	DOXYGEN PERL\
			GEOID_EGM96_5 GRAVITY_EGM96 GRAVITY_WGS84\
			MAGNETIC_WMM2015 MAGNETIC_IGRF12
PERL_DESC=	Build documentation with pod2man and pod2html
OPTIONS_GROUP=	DATASETS
OPTIONS_SUB=	yes
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENV_OFF=	ac_cv_prog_DOXYGEN=
PERL_USE=	PERL5=build
PERL_USES=	perl5
PERL_CONFIGURE_ENV_OFF=	ac_cv_prog_POD2MAN= ac_cv_prog_POD2HTML=

GEOID_NAMES=		egm84-30 egm84-15 egm96-15 egm96-5\
			egm2008-5 egm2008-2_5 egm2008-1
GRAVITY_NAMES=		egm84 egm96 egm2008 wgs84 grs80
MAGNETIC_NAMES=		wmm2010 wmm2015 igrf11 igrf12 emm2010 emm2015

.for n in ${GEOID_NAMES}
GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=		Install ${n} geoid dataset
OPTIONS_GROUP_DATASETS+=	GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}
GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	geoids-distrib/${n}.tar.bz2:geoids
MAKESUM_OPTIONS_DEFAULT+=	GEOID_${n:C/[^0-9A-Z_a-z]/_/g:tu}
.endfor
.for n in ${GRAVITY_NAMES}
GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=	Install ${n} gravity model
OPTIONS_GROUP_DATASETS+=	GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}
GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	gravity-distrib/${n}.tar.bz2:gravity
MAKESUM_OPTIONS_DEFAULT+=	GRAVITY_${n:C/[^0-9A-Z_a-z]/_/g:tu}
.endfor
.for n in ${MAGNETIC_NAMES}
MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DESC=	Install ${n} magnetic model
OPTIONS_GROUP_DATASETS+=	MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}
MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}_DISTFILES=	magnetic-distrib/${n}.tar.bz2:magnetic
MAKESUM_OPTIONS_DEFAULT+=	MAGNETIC_${n:C/[^0-9A-Z_a-z]/_/g:tu}
.endfor

# Memorandum: use "make fetch makesum" to makesum all distfiles.
.ifmake makesum || distclean
OPTIONS_DEFAULT=	${MAKESUM_OPTIONS_DEFAULT}
.endif

post-patch:
	${REINPLACE_CMD} -e '/wget/s/wget -O/fetch -o /'\
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
