# New ports collection makefile for:	emboss
# Date created:		31 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	emboss
PORTVERSION=	2.2.0
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.uk.embnet.org/pub/EMBOSS/ \
		ftp://ftp.es.embnet.org/pub/software/emboss/EMBOSS/ \
		ftp://ftp.ebi.ac.uk/pub/software/unix/EMBOSS/
DISTFILES=	${PORTNAME:U}-${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME:U}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	wjv@FreeBSD.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_XLIB=	yes
USE_MOTIF=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include/gd" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
SCRIPTS_ENV+=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		MKDIR="${MKDIR}" RM="${RM}"

WRKSRC=		${WRKDIR}/${PORTNAME:U}-${PORTVERSION}
EMBASSY_WRKDIR=	${WRKSRC}/EMBASSY
EMNU_VERSION=	1.0.5
HMMER_VERSION=	2.1.1
MEME_VERSION=	2.3.1
MSE_VERSION=	0.0.4
TOPO_VERSION=	0.1
PHYLIP_VERSION=	3.573c
DOC_DIRS=	doc/manuals doc/tutorials doc/programs/text doc/programs/html
CONFIG_FILE=	${WRKSRC}/emboss/emboss.default.template

.for app in EMNU HMMER MEME MSE PHYLIP TOPO
SCRIPTS_ENV+=	${app}_VERSION="${${app}_VERSION}"
.if defined(WITH_${app})
APPLIST+=	${app}
${app}_WRKSRC=	${EMBASSY_WRKDIR}/${app}-${${app}_VERSION}
${app}_DISTFILE=${app}-${${app}_VERSION}${EXTRACT_SUFX}
DISTFILES+=	${${app}_DISTFILE}
PLIST_${app}=	""
.else
PLIST_${app}=	"@comment "
.endif
PLIST_SUB+=	PLIST_${app}=${PLIST_${app}}
.endfor

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
	  's#\$$\(prefix\)/share/\$$\(PACKAGE\)/doc#\$$\(datadir\)/doc/\$$\(PACKAGE\)#' \
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

post-install:
.for app in ${APPLIST}
	@ (cd ${${app}_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} \
	  ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor
	@ ${PERL} -pe 's#%%PREFIX%%#${PREFIX}#' \
	  ${CONFIG_FILE} > ${PREFIX}/etc/emboss.default.sample && \
	  ${CHOWN} ${SHAREOWN}:${SHAREGRP} \
	  ${PREFIX}/etc/emboss.default.sample
	@ ${PERL} -pe 's#%%PREFIX%%#${PREFIX}#' \
	  pkg-message > ${PKGMESSAGE}
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

post-clean:
	@ ${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
