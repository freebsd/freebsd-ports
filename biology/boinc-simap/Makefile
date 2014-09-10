# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	boinc-simap
PORTVERSION=	${SIMAP_VERSION}.${HMMER_VERSION}
PORTREVISION=	7
CATEGORIES=	biology
MASTER_SITES=	http://boincsimap.org/boincsimap/download/
DISTNAME=	${SIMAP_BINARY} ${HMMER_BINARY}
EXTRACT_ONLY=	${HMMER_BINARY}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Similarity Matrix of Proteins project for BOINC

LIB_DEPENDS=	libc.so.6:${PORTSDIR}/misc/compat6x
RUN_DEPENDS=	boinc_client:${PORTSDIR}/net/boinc-client

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
STRIP=		#

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_CLIENT_USER?=	boinc
BOINC_CLIENT_GROUP?=	nobody
BOINC_CLIENT_HOME?=	/var/db/boinc

SIMAP_SITE=	boincsimap.org_boincsimap
SIMAP_BINARY=	simap_${SIMAP_VERSION}_${MACH}-pc-freebsd
SIMAP_VERSION=	5.10
HMMER_BINARY=	hmmer_${HMMER_VERSION}_${MACH}-pc-freebsd
HMMER_VERSION=	5.09
EXTRACT_AFTER_ARGS+=	--include=${HMMER_BINARY}

PLIST_SUB=	SIMAP_BINARY=${SIMAP_BINARY} HMMER_BINARY=${HMMER_BINARY} \
		SIMAP_SITE=${SIMAP_SITE} \
		BOINC_CLIENT_HOME=${BOINC_CLIENT_HOME} \
		BOINC_CLIENT_USER=${BOINC_CLIENT_USER} \
		BOINC_CLIENT_GROUP=${BOINC_CLIENT_GROUP}

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	SSE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSE}
MACH=		i686
.else
MACH=		i386
.endif

.if ${ARCH} == amd64
AMD64=		""
.else
AMD64=		"@comment "
.endif

SUB_FILES=	app_info.xml pkg-message
SUB_LIST=	SIMAP_BINARY=${SIMAP_BINARY} HMMER_BINARY=${HMMER_BINARY} \
		SIMAP_APPVERSION=${SIMAP_VERSION:S/.//} \
		HMMER_APPVERSION=${HMMER_VERSION:S/.//} AMD64=${AMD64} \
		BOINC_CLIENT_HOME=${BOINC_CLIENT_HOME}

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${SIMAP_BINARY} ${WRKDIR}
	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
	    ${DISTDIR}/${HMMER_BINARY}.tar.gz ${EXTRACT_AFTER_ARGS})

do-install:
	${INSTALL} -d ${STAGEDIR}${BOINC_CLIENT_HOME}/projects
	${INSTALL} -d ${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SIMAP_SITE}
	${INSTALL_DATA} ${WRKDIR}/app_info.xml \
	    ${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SIMAP_SITE}
.for APP in ${DISTNAME}
	${INSTALL_PROGRAM} ${WRKDIR}/${APP} \
	    ${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SIMAP_SITE}
.endfor

.include <bsd.port.mk>
