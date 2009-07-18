# New ports collection makefile for:	boinc-setiathome-enhanced
# Date created:				26 March 2006
# Whom:					Rene Ladan <r.c.ladan@student.tue.nl>
# $FreeBSD$
#

PORTNAME=	boinc-setiathome-enhanced
PORTVERSION=	${SETI_PORTVERSION_FULL}.${AP_PORTVERSION_FULL}
PORTREVISION=	3
CATEGORIES=	astro
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/
DISTFILES=	astropulse-${AP_PORTVERSION_FULL}.tar.bz2 setiathome-${SETI_PORTVERSION_FULL}.tar.bz2

MAINTAINER=	rene@freebsd.org
COMMENT=	Setiathome Enhanced/Astropulse for BOINC

# don't use USE_AUTOTOOLS because we want to invoke it in a non-default way
BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3 \
		${LOCALBASE}/include/boinc/std_fixes.h:${PORTSDIR}/net/boinc-client \
		${LOCALBASE}/bin/autoconf-2.62:${PORTSDIR}/devel/autoconf262 \
		${LOCALBASE}/bin/automake-1.8:${PORTSDIR}/devel/automake18 \
		${LOCALBASE}/bin/autoconf:${PORTSDIR}/devel/autoconf-wrapper \
		${LOCALBASE}/bin/automake:${PORTSDIR}/devel/automake-wrapper \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	boinc_client:${PORTSDIR}/net/boinc-client
LIB_DEPENDS=	fftw3f:${PORTSDIR}/math/fftw3-float \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		xcb.2:${PORTSDIR}/x11/libxcb

USE_GL=		gl glu glut
USE_XORG=	ice sm x11 xau xext xi xdamage xdmcp xfixes xmu xt xxf86vm

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
NO_WRKSUBDIR=	yes

SETI_PORTVERSION=6.3
SETI_PORTVERSION_FULL=6.03
AP_PORTVERSION=5.0
AP_PORTVERSION_FULL=5.00

CFLAGS+=	-I${LOCALBASE}/include/boinc -O2 -I${LOCALBASE}/include -L${LOCALBASE}/lib
.if defined(CPUTYPE)
CFLAGS+=	-march=${CPUTYPE}
.endif

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_USER?=	boinc
BOINC_GROUP?=	nobody
BOINC_HOME?=	/var/db/boinc

OPTIONS=	SETI_APP	"Install SETI@home binary" on \
		AP_APP		"Install Astropulse binary" on

.include <bsd.port.pre.mk>

.if (${OSVERSION} >= 700000)
CFLAGS+=	-mtune=native
.endif
CXXFLAGS+=	${CFLAGS}

CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" \
		BOINCDIR="${LOCALBASE}" \
		BOINC_DIR="${LOCALBASE}"
CONFIGURE_FLAGS+=	--disable-static-client --with-boinc-platform=${ARCH}-portbld-freebsd --build=${ARCH}-portbld-freebsd

.if ${OSVERSION} >= 700042
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.if defined(WITHOUT_SETI_APP) && defined(WITHOUT_AP_APP)
IGNORE=	neither SETI@home nor Astropulse selected
.endif

SETI_SITE=	setiathome.berkeley.edu
SETI_BINARY=	setiathome-${SETI_PORTVERSION}.${ARCH}-portbld-freebsd
AP_BINARY=	astropulse-${AP_PORTVERSION}.${ARCH}-portbld-freebsd

PLIST_SUB=	SETI_BINARY=${SETI_BINARY} \
		AP_BINARY=${AP_BINARY} \
		SETI_SITE=${SETI_SITE} \
		BOINC_HOME=${BOINC_HOME}

do-configure:
.if !defined(WITHOUT_AP_APP)
	(cd ${WRKDIR}/astropulse/client ; ${REINPLACE_CMD} -E -e "s|/bin/sh|${LOCALBASE}/bin/bash|" ./configure ; ${CONFIGURE_ENV} ./configure ${CONFIGURE_FLAGS})
.endif
	# always configure seti@home, the astropulse source code relies on it
	(cd ${WRKDIR}/seti_boinc ; ./_autosetup ; ${REINPLACE_CMD} -E -e "s|/bin/sh|${LOCALBASE}/bin/bash|" ./configure ; ${CONFIGURE_ENV} ./configure ${CONFIGURE_FLAGS} --disable-server)

do-build:
	@${ECHO_CMD} "<app_info>" >> ${WRKDIR}/app_info.xml
.if !defined(WITHOUT_AP_APP)
	(cd ${WRKDIR}/astropulse/client ; ${GMAKE})
	#add app_info tags for astropulse
	@${ECHO_CMD} "<app>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<name>astropulse</name>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "</app>" >> ${WRKDIR}/app_info.xml

	@${ECHO_CMD} "<file_info>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<name>${AP_BINARY}</name>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<executable/>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "</file_info>" >> ${WRKDIR}/app_info.xml

	@${ECHO_CMD} "<app_version>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<app_name>astropulse</app_name>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<version_num>${AP_PORTVERSION_FULL:S/.//}</version_num>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<file_ref>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<file_name>${AP_BINARY}</file_name>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<main_program/>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "</file_ref>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "</app_version>" >> ${WRKDIR}/app_info.xml
.endif
.if !defined(WITHOUT_SETI_APP)
	(cd ${WRKDIR}/seti_boinc ; ${GMAKE})
	#add app_info tags for setiathome
	@${ECHO_CMD} "<app>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<name>setiathome_enhanced</name>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "</app>" >> ${WRKDIR}/app_info.xml

	@${ECHO_CMD} "<file_info>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<name>${SETI_BINARY}</name>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<executable/>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "</file_info>" >> ${WRKDIR}/app_info.xml

	@${ECHO_CMD} "<app_version>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<app_name>setiathome_enhanced</app_name>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<version_num>${SETI_PORTVERSION_FULL:S/.//}</version_num>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<file_ref>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<file_name>${SETI_BINARY}</file_name>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "<main_program/>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "</file_ref>" >> ${WRKDIR}/app_info.xml
	@${ECHO_CMD} "</app_version>" >> ${WRKDIR}/app_info.xml
.endif
	@${ECHO_CMD} "</app_info>" >> ${WRKDIR}/app_info.xml

do-install:
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects/${SETI_SITE}
.if !defined(WITHOUT_SETI_APP)
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/seti_boinc/client/${SETI_BINARY} ${BOINC_HOME}/projects/${SETI_SITE}/
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/seti_boinc/client/seti_graphics ${BOINC_HOME}/projects/${SETI_SITE}/
.endif
.if !defined(WITHOUT_AP_APP)
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/astropulse/client/${AP_BINARY} ${BOINC_HOME}/projects/${SETI_SITE}/
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/astropulse/client/ap_graphics ${BOINC_HOME}/projects/${SETI_SITE}/
.endif
	${INSTALL_DATA} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/app_info.xml ${BOINC_HOME}/projects/${SETI_SITE}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
