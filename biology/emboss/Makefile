# New ports collection makefile for:	emboss
# Date created:		31 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	emboss
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.uk.embnet.org/pub/EMBOSS/ \
		ftp://ftp.no.embnet.org/pub/EMBOSS/
DISTFILES=	${PORTNAME:U}-${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME:U}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	johann@egenetics.com

LIB_DEPENDS=	gd.1:${PORTSDIR}/graphics/gd \
		png.4:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_XLIB=	yes
PLIST=		${WRKDIR}/pkg-plist

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include/gd" \
		LIBS="-L${LOCALBASE}/lib"

SCRIPTS_ENV+=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		MKDIR="${MKDIR}" \
		RM="${RM}"

WRKSRC=		${WRKDIR}/${PORTNAME:U}-${PORTVERSION}
EMBASSY_WRKDIR=	${WRKSRC}/EMBASSY
PHYLIP_VERSION=	3.573c
MSE_VERSION=	0.0.4
TOPO_VERSION=	0.1
.for app in MSE PHYLIP TOPO
SCRIPTS_ENV+=	${app}_VERSION="${${app}_VERSION}"
.if defined(WITH_${app})
APPLIST+=	${app}
PLISTS+=	${PKGDIR}/pkg-plist.${app}
${app}_WRKSRC=	${EMBASSY_WRKDIR}/${app}-${${app}_VERSION}
${app}_DISTFILE=${app}-${${app}_VERSION}${EXTRACT_SUFX}
DISTFILES+=	${${app}_DISTFILE}
.endif
.endfor
PLISTS+=	${PKGDIR}/pkg-plist
DOC_DIRS=	doc/manuals doc/tutorials doc/programs/text doc/programs/html

pre-fetch:
	@ ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.${PORTNAME}

post-extract:
.for app in ${APPLIST}
	@ ${MKDIR} ${EMBASSY_WRKDIR}
	@ cd ${EMBASSY_WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
	  ${_DISTDIR}/${${app}_DISTFILE} ${EXTRACT_AFTER_ARGS}
	@ if [ `id -u` = 0 ]; then \
	    ${CHMOD} -R ug-s ${${app}_WRKSRC}; \
	    ${CHOWN} -R 0:0 ${${app}_WRKSRC}; \
	  fi
.endfor

post-patch:
.for DIR in ${DOC_DIRS}
	@ ${PERL} -pi.orig -e \
	  "s#share/\\$$\(PACKAGE\)/doc#share/doc/\\$$\(PACKAGE\)#" \
	  ${WRKSRC}/${DIR}/Makefile.in
.endfor

post-configure:
.for app in ${APPLIST}
	@ (cd ${${app}_WRKSRC} && \
	  ${SETENV} CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
	  CXXFLAGS="${CXXFLAGS}" \
	  INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	  INSTALL_DATA="${INSTALL_DATA}" \
	  INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	  INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	  ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})
.endfor

post-build:
.for app in ${APPLIST}
	@ (cd ${${app}_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} \
	  ${MAKE_ARGS})
.endfor

pre-install:
	@ ${CAT} ${PLISTS} > ${PLIST}

post-install:
.for app in ${APPLIST}
	@ (cd ${${app}_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} \
	  ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/emboss/acd/emboss.default \
	  ${PREFIX}/etc/emboss.default.sample
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

post-clean:
	@ ${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
