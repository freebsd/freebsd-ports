# Created by: rene
# $FreeBSD$

PORTNAME=	boinc-setiathome
PORTVERSION=	8.00
PORTREVISION=	3
CATEGORIES=	astro
MASTER_SITES=	LOCAL/ler/setiathome \
		http://www.lerctr.org/setiathome/
DISTNAME=	setiathome-svn-3727  # no releases available, snapshot

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Setiathome Enhanced for BOINC

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		fails to link: vector/analyzeFuncs_vector.cpp:(.data+0x38): undefined symbol 'vfp_GetPowerSpectrum(float (*) [2], float*, int)'
BROKEN_armv6=		fails to compile: vector/analyzeFuncs_neon.S:178:17: invalid instruction, did you mean: neg?
BROKEN_armv7=		fails to compile: vector/analyzeFuncs_neon.S:178:17: invalid instruction, did you mean: neg?

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
RUN_DEPENDS=	boinc_client:net/boinc-client
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float

USES=		autoreconf compiler:c++11-lang gmake gnome libtool pkgconfig \
		tar:xz

GNU_CONFIGURE=	yes

CFLAGS+=	-O2 -I${LOCALBASE}/include/boinc -I${LOCALBASE}/include \
		-L${LOCALBASE}/lib
LDFLAGS+=	-lexecinfo
.if defined(CPUTYPE)
CFLAGS+=	-march=${CPUTYPE}
.endif

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_CLIENT_USER?=	boinc
BOINC_CLIENT_GROUP?=	boinc
BOINC_CLIENT_HOME?=	/var/db/boinc

OPTIONS_DEFINE=	X11

X11_DESC=	Build screensaver (requires net/boinc-client with X11)

OPTIONS_SUB=	yes

X11_BUILD_DEPENDS=	${LOCALBASE}/lib/libboinc_graphics2.a:net/boinc-client
X11_USES=		gl jpeg xorg
X11_USE=		GL=gl,glu,glut \
			XORG=ice,sm,x11,xau,xcb,xext,xi,xdamage,xdmcp,xfixes,xmu,xt,xxf86vm
X11_CONFIGURE_ENABLE=	graphics

X11_BUILD_DEPENDS_OFF=	${LOCALBASE}/include/boinc/std_fixes.h:net/boinc-client

CFLAGS_i386=	-mtune=native
CFLAGS_amd64=	-mtune=native

.if !empty(MACHINE_CPU:Maltivec)
CONFIGURE_ARGS+=	--enable-altivec
.endif

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} == 60
CFLAGS+=	-Wno-reserved-user-defined-literal -Wno-unused-command-line-argument
.endif

CONFIGURE_ENV+=	BOINCDIR="${NONEXISTENT}"

CONFIGURE_ARGS+=	--disable-static-client --disable-server \
			--disable-tests \
			--with-boinc-platform=${ARCH}-portbld-freebsd

SETI_SITE=	setiathome.berkeley.edu
SETI_BINARY=	setiathome-${PORTVERSION:S/.0/./}.${ARCH}-portbld-freebsd

SUB_FILES=	pkg-deinstall pkg-install pkg-message
SUB_LIST=	SETI_BINARY=${SETI_BINARY} \
		SETI_SITE=${SETI_SITE} \
		SETI_VERSION=${PORTVERSION:S/.//} \
		BOINC_CLIENT_HOME=${BOINC_CLIENT_HOME} \
		BOINC_CLIENT_USER=${BOINC_CLIENT_USER} \
		BOINC_CLIENT_GROUP=${BOINC_CLIENT_GROUP}
PLIST_SUB+=	PREFIX=${PREFIX} \
		SETI_BINARY=${SETI_BINARY} \
		SETI_SITE=${SETI_SITE} \
		BOINC_CLIENT_HOME=${BOINC_CLIENT_HOME} \
		BOINC_CLIENT_USER=${BOINC_CLIENT_USER} \
		BOINC_CLIENT_GROUP=${BOINC_CLIENT_GROUP}

# str_replace.h is included in newer versions of net/boinc-client,
# but it is not needed on FreeBSD
post-patch:
	${REINPLACE_CMD} -E -e "s|#include \"str_replace.h\"||" \
		${WRKSRC}/client/main.cpp \
		${WRKSRC}/client/sah_gfx.cpp \
		${WRKSRC}/client/seti.cpp \
		${WRKSRC}/client/timecvt.cpp \
		${WRKSRC}/db/xml_util.cpp

do-install:
	${INSTALL} -d ${STAGEDIR}${BOINC_CLIENT_HOME}/projects
	${INSTALL} -d ${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SETI_SITE}
	${INSTALL_PROGRAM} ${WRKSRC}/client/${SETI_BINARY} \
	    ${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SETI_SITE}/
do-install-X11-on:
	${INSTALL_PROGRAM} ${WRKSRC}/client/seti_graphics \
	    ${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SETI_SITE}/

.include <bsd.port.post.mk>
