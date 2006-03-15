# New ports collection makefile for:	boinc-setiathome
# Date created:				01 October 2004
# Whom:					J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	boinc-setiathome
PORTVERSION=	4.18
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DISTNAME=	seti_boinc-${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Setiathome for boinc

BUILD_DEPENDS=	boinc_client:${PORTSDIR}/net/boinc-client
RUN_DEPENDS=	boinc_client:${PORTSDIR}/net/boinc-client

.if !defined(WITHOUT_FFTW)
LIB_DEPENDS+=	fftw.2:${PORTSDIR}/math/fftw
.endif

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/seti_boinc

CONFLICTS=	boinc-setiathome-naparst-[0-9]*

# disable gui, it's broken anyway
CONFIGURE_ARGS=	--disable-server --disable-gui
CONFIGURE_ENV=	LANG=C BOINCDIR=${LOCALBASE} CXXFLAGS="-I${LOCALBASE}/include ${CFLAGS} -O3" LDFLAGS=-L${LOCALBASE}/lib CFLAGS="${CFLAGS} -O3"
MAKE_ENV=	LANG=C

# these must match settings in ../../net/boinc-client/Makefile
BOINC_USER?=	boinc
BOINC_GROUP?=	nobody
BOINC_HOME?=	/var/db/boinc

SETI_SITE=	setiathome.berkeley.edu
SETI_BINARY=	setiathome

PLIST_SUB=	SETI_BINARY="${SETI_BINARY}" SETI_SITE=${SETI_SITE} \
		BOINC_HOME=${BOINC_HOME}

SUB_FILES=	app_info.xml
SUB_LIST=	SETI_BINARY="${SETI_BINARY}" SETI_NODOTVER="${PORTVERSION:S/.//}"

.include <bsd.port.pre.mk>

# Disable on FreeBSD 4.x; boinc-client is BROKEN too
.if ${OSVERSION} < 500000
BROKEN=		Does not compile. Consider upgrading your FreeBSD to at least 5.X
.endif

do-install:
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects/${SETI_SITE}
	${INSTALL_DATA} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/app_info.xml ${BOINC_HOME}/projects/${SETI_SITE}
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKSRC}/client/setiathome-${PORTVERSION}.${CONFIGURE_TARGET} ${BOINC_HOME}/projects/${SETI_SITE}/${SETI_BINARY}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
