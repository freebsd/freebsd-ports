# Created by: Tatsuki Makino <tatsuki_makino@hotmail.com>
# $FreeBSD$

PORTNAME=	geographiclib
PORTVERSION=	1.37
PORTREVISION=	1
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
WRKSRC=		${WRKDIR}/${DISTNAME}
NO_WRKSUBDIR=	yes
PORTDOCS=	*
GNU_CONFIGURE=	yes
MAKE_ARGS+=	geographiclib_data=${DATADIR:Q}
MAKE_ARGS+=	pythondir=${PYTHON_SITELIBDIR}/geographiclib
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

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

install-datasets-mkdir: .NOTMAIN
	for d in geoids gravity magnetic ;\
	do ${MKDIR} ${STAGEDIR}${DATADIR}/$${d} &&\
		${TOUCH} ${STAGEDIR}${DATADIR}/$${d}/.keep ;\
	done
.PHONY: install-datasets-mkdir

.for n in geoids gravity magnetic
install-datasets-${n}: install-datasets-mkdir .NOTMAIN
	(cd ${WRKDIR}/${n} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${n})
.PHONY: install-datasets-${n}
.endfor

post-install: install-datasets-mkdir
.if ${PORT_OPTIONS:MGEOID_*}
post-install: install-datasets-geoids
.endif
.if ${PORT_OPTIONS:MGRAVITY_*}
post-install: install-datasets-gravity
.endif
.if ${PORT_OPTIONS:MMAGNETIC_*}
post-install: install-datasets-magnetic
.endif

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
