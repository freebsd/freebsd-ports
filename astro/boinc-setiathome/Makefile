# New ports collection makefile for:	boinc-setiathome
# Date created:				01 October 2004
# Whom:					J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	boinc-setiathome
PORTVERSION=	4.07.20050601
CATEGORIES=	astro
MASTER_SITES=	http://setiweb.ssl.berkeley.edu/sah/seti_source/nightly/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DISTNAME=	seti_boinc-client-cvs-2005-06-01

MAINTAINER=	fbsd@opal.com
COMMENT=	Setiathome for boinc

.include <bsd.port.pre.mk>

# Disable GUI on FreeBSD 4.x due to problems with wxgtk lib
.if ${OSVERSION} < 500000
WITHOUT_X11=	yes
.endif

BUILD_DEPENDS+=	${LOCALBASE}/lib/boinc/boinc-client:${PORTSDIR}/net/boinc-client
RUN_DEPENDS+=	boinc:${PORTSDIR}/net/boinc-client
LIB_DEPENDS+=	fftw.2:${PORTSDIR}/math/fftw
.if !defined(WITHOUT_X11)
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg \
		glut:${PORTSDIR}/graphics/libglut
.endif

USE_AUTOMAKE_VER=	19
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_LIBTOOL_VER=	15
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.endif

WRKSRC=		${WRKDIR}/seti_boinc

CONFIGURE_ARGS=	--disable-server
.if !defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--disable-dynamic-graphics
.else
CONFIGURE_ARGS+=	--disable-gui
.endif
CONFIGURE_ENV=	LANG=C BOINCDIR=${LOCALBASE} CPPFLAGS=-I${X11BASE}/include CXXFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" LDFLAGS=-L${LOCALBASE}/lib
MAKE_ENV=	LANG=C

# these must match settings in ../../net/boinc-client/Makefile
BOINC_USER=	boinc
BOINC_GROUP=	nobody
BOINC_HOME=	/var/db/boinc

SETI_SITE=	setiathome.berkeley.edu
SETI_BINARY=	setiathome

PLIST_SUB=	SETI_BINARY="${SETI_BINARY}" SETI_SITE=${SETI_SITE} \
		BOINC_HOME=${BOINC_HOME}
.if !defined(WITHOUT_X11)
PLIST_SUB+=	BOINC_GUI=""
.else
PLIST_SUB+=	BOINC_GUI="@comment "
.endif

SUB_FILES=	app_info.xml pkg-install
SUB_LIST=	SETI_BINARY="${SETI_BINARY}" SETI_SITE="${SETI_SITE}" \
		BOINC_HOME="${BOINC_HOME}" BOINC_USER="${BOINC_USER}" \
		BOINC_GROUP="${BOINC_GROUP}"

FIND_SETI_BINARY=(cd ${WRKSRC}/client; make -V CLIENT_PROG)

pre-configure:
	${TOUCH} ${WRKSRC}/missing
	cd ${WRKSRC}; ${ACLOCAL} -I ${LOCALBASE}/share/libtool${USE_LIBTOOL_VER}/libltdl -I m4

do-install:
	${MKDIR} ${BOINC_HOME}/projects/${SETI_SITE}
	${INSTALL_DATA} ${WRKDIR}/app_info.xml ${BOINC_HOME}/projects/${SETI_SITE}
	${INSTALL_PROGRAM} ${WRKSRC}/client/`${FIND_SETI_BINARY}` ${PREFIX}/lib/boinc/${SETI_BINARY}
.if !defined(WITHOUT_X11)
	#${INSTALL_PROGRAM} ${WRKSRC}/client/`${FIND_SETI_BINARY}`.so ${PREFIX}/lib/boinc/${SETI_BINARY}.so
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
