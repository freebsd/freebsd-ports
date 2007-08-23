# New ports collection makefile for:	boinc-setiathome-enhanced
# Date created:				26 March 2006
# Whom:					Rene Ladan <r.c.ladan@student.tue.nl>
# $FreeBSD$
#

PORTNAME=	boinc-setiathome-enhanced
PORTVERSION=	5.27
CATEGORIES=	astro
MASTER_SITES=	http://home.tiscali.nl/rladan/distfiles/

MAINTAINER=	r.c.ladan@gmail.com
COMMENT=	Setiathome Enhanced for BOINC

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3 \
		${LOCALBASE}/include/BOINC/std_fixes.h:${PORTSDIR}/net/boinc-client
# fftw3f is statically linked :
LIB_DEPENDS=	fftw3f:${PORTSDIR}/math/fftw3-float
RUN_DEPENDS=	boinc_client:${PORTSDIR}/net/boinc-client

USE_GMAKE=	yes

# The compiler flags below are copied from m4/optimizations.m4,
# leaving out the -march flag which is set by /usr/share/mk/bsd.cpu.mk
.if ${MACHINE_CPU:Msse3}
CFLAGS+=	-msse3
.elif ${MACHINE_CPU:Msse2}
CFLAGS+=	-msse2
.elif ${MACHINE_CPU:Msse}
CFLAGS+=	-msse
.endif
.if ${MACHINE_CPU:Mmmx}
CFLAGS+=	-mmmx
.endif
.ifdef ${MACHINE_CPU:M3dnow}
CFLAGS+=	-m3dnow
.endif
.if ${MACHINE_CPU:Msse3} || ${MACHINE_CPU:Msse2} || ${MACHINE_CPU:Msse}
CFLAGS+=	-mfpmath=sse
.else
CFLAGS+=	-mfpmath=387
.endif
# From http://www,lb.shuttle.de/apastron/boincDown.shtml :
# what about other 64 bit archs (especially S/390, see gcc.info.gz) ?
.ifdef ${MACHINE_CPU:Mamd64}
CFLAGS+=	-m64
.endif
# no SPARC options (-mvis) available for autodection

CFLAGS+=	-I${LOCALBASE}/include -funroll-loops -ffast-math -O3
CXXFLAGS+=	${CFLAGS}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" \
		BOINCDIR="${LOCALBASE}"

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_USER?=	boinc
BOINC_GROUP?=	nobody
BOINC_HOME?=	/var/db/boinc

SETI_SITE=	setiathome.berkeley.edu
SETI_BINARY=	setiathome-${PORTVERSION}.${ARCH}-portbld-freebsd

SUB_FILES=	app_info.xml
SUB_LIST=	STRIPPED_PORTVERSION=${PORTVERSION:S/.//} \
		SETI_BINARY="${SETI_BINARY}"

PLIST_SUB=	SETI_BINARY="${SETI_BINARY}" SETI_SITE=${SETI_SITE} \
		BOINC_HOME=${BOINC_HOME}

PORTDOCS=	AUTHORS COPYING COPYRIGHT README checkin_notes
do-install:
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects/${SETI_SITE}
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKSRC}/client/${SETI_BINARY} ${BOINC_HOME}/projects/${SETI_SITE}/
	${INSTALL_DATA} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/app_info.xml ${BOINC_HOME}/projects/${SETI_SITE}/
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}/${file}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
