# New ports collection makefile for:   boinc-setiathome
# Date created:        01 October 2004
# Whom:                J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	boinc-setiathome
PORTVERSION=	4.07
CATEGORIES=	astro
MASTER_SITES=	http://boinc.berkeley.edu/seti_source/nightly/
DISTNAME=	seti_boinc-client-cvs-2004-11-09

MAINTAINER=	fbsd@opal.com
COMMENT=	Setiathome for boinc

BUILD_DEPENDS=	${LOCALBASE}/boinc/api/boinc_api.h:${PORTSDIR}/net/boinc-client
RUN_DEPENDS=	boinc-client:${PORTSDIR}/net/boinc-client
LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

BROKEN=		Unfetchable

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	LANG=C BOINCDIR=${LOCALBASE}/boinc CPPFLAGS=-I${X11BASE}/include CFLAGS=-I${X11BASE}/include LDFLAGS=-L${LOCALBASE}/lib
MAKE_ENV=	LANG=C
USE_GMAKE=	yes
PKGINSTALL=	${WRKDIR}/pkg-install

WRKSRC=		${WRKDIR}/seti_boinc/client
CONFIGURE_WRKSRC=${WRKDIR}/seti_boinc/

FIND_SETI_BINARY=(cd ${WRKSRC}; make -V PROG)
SETI_SITE?=	setiathome.berkeley.edu
PLIST_SUB=	SETI_SITE=${SETI_SITE} BOINC_HOME=${BOINC_HOME}

# these must match settings in ../../net/boinc-client/Makefile
BOINC_USER=	boinc
BOINC_HOME=	/var/db/boinc
BOINC_DATADIR=	${PREFIX}/boinc

# ${TOUCH} ${WRKDIR}/seti_boinc/db/schema_master.cpp
pre-patch:
	${TOUCH} ${WRKDIR}/seti_boinc/client/dependencies
	${TOUCH} ${WRKDIR}/seti_boinc/db/dependencies

post-build:
	${SED} -e "s:%%SETI_BINARY%%:`${FIND_SETI_BINARY}`:g" \
	  -e "s:%%SETI_SITE%%:${SETI_SITE}:g" \
	  -e "s:%%BOINC_DATADIR%%:${BOINC_DATADIR}:g" \
	  < ${FILESDIR}/app_info.xml > ${WRKDIR}/app_info.xml
	${SED} -e "s:%%SETI_SITE%%:${SETI_SITE}:g" \
	  -e "s:%%BOINC_HOME%%:${BOINC_HOME}:g" \
	  -e "s:%%BOINC_USER%%:${BOINC_USER}:g" \
	  < pkg-install > ${WRKDIR}/pkg-install

do-install:
	${MKDIR} ${PREFIX}/boinc/projects/${SETI_SITE}
	${INSTALL_PROGRAM} ${WRKSRC}/`${FIND_SETI_BINARY}` ${PREFIX}/boinc/projects/${SETI_SITE}
	${INSTALL_DATA} ${WRKDIR}/app_info.xml ${PREFIX}/boinc/projects/${SETI_SITE}
	${MKDIR} ${BOINC_HOME}/projects/${SETI_SITE}/
	${LN} -s ${PREFIX}/boinc/projects/${SETI_SITE}/`${FIND_SETI_BINARY}` ${BOINC_HOME}/projects/${SETI_SITE}
	${LN} -s ${PREFIX}/boinc/projects/${SETI_SITE}/app_info.xml ${BOINC_HOME}/projects/${SETI_SITE}

post-install:
	${REINPLACE_CMD} \
	  -e "s:%%SETI_BINARY%%:`${FIND_SETI_BINARY}`:g" \
	  -e "s:%%BOINC_HOME%%:${BOINC_HOME}:g" ${TMPPLIST}
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
