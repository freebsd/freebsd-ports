# New ports collection makefile for: OpenOffice
# Date created:		28 Februar 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice
PORTVERSION=	641c
CATEGORIES=	editors
MASTER_SITES=	http://sf1.mirror.openoffice.org/641c/ \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/ \
		ftp://ftp.netbsd.org/pub/NetBSD/misc/mrauch/ 
DISTFILES=	oo_${PORTVERSION}_src.tar.bz2 gpc231.tar.Z oo_moz_641.tar.gz
EXTRACT_ONLY=	oo_${PORTVERSION}_src.tar.bz2
EXTRACT_REST=	gpc231.tar.Z oo_moz_641.tar.gz

MAINTAINER=	mbr@FreeBSD.org
BROKEN=		'Work in progress -- does not build yet till the end'

USE_BZIP2= yes
EXTRACT_BEFORE_ARGS_R= -dc
EXTRACT_AFTER_ARGS_R= | ${TAR} -xf -
EXTRACT_CMD_R= ${GZIP_CMD}

GCC_VERSION!=	${CC} --version
JDK13DIR?=      ${LOCALBASE}/jdk1.3.1
JAVAVM=         ${JDK13DIR}/bin/java

BUILD_DEPENDS=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
BUILD_DEPENDS+= bison:${PORTSDIR}/devel/bison
BUILD_DEPENDS+= gmake:${PORTSDIR}/devel/gmake
BUILD_DEPENDS+= zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+= ${JAVAVM}:${PORTSDIR}/java/jdk13
BUILD_DEPENDS+= pth-config:${PORTSDIR}/devel/pth

GNU_CONFIGURE=	yes
WRKSRC=	${WRKDIR}/oo_${PORTVERSION}_src/config_office

CONFIGURE_ARGS+=	--with-stlport4-home=${PREFIX} \
			--with-jdk-home=${JDK13DIR}

.include <bsd.port.pre.mk>

pre-fetch:
.if ${GCC_VERSION}!="2.95.2" && ${GCC_VERSION}!="2.95.3"
	@ ${ECHO}
	@ ${ECHO} Openoffice requires gcc 2.95.2 or better
	@ ${ECHO}
	@ ${FALSE}
.endif
.if ${OSVERSION} < 500031
	@${ECHO}
	@${ECHO} OS-VERSION ${OSVERSION}
	@${ECHO}
	@${ECHO} Openoffice depends on OS-Fixes which are
	@${ECHO} not yet available.
	@${FALSE}
.endif

pre-extract:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Can\'t open display:
	@ ${ECHO} Please check your DISPLAY variable.
	@ ${ECHO}
	@ ${FALSE}
.endif

post-extract:
	@for file in ${EXTRACT_REST}; do \
		if ! (cd ${WRKDIR} && ${EXTRACT_CMD_R} \
			${EXTRACT_BEFORE_ARGS_R} \
			${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS_R}) ; \
		then \
			exit 1; \
		fi \
	done
	${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/../external/gpc/
	${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/../external/gpc/
	${CP} ${WRKDIR}/NETBSDGCCIinc.zip ${WRKSRC}/../moz/zipped/FREEBSDGCCIinc.zip
	${CP} ${WRKDIR}/NETBSDGCCIlib.zip ${WRKSRC}/../moz/zipped/FREEBSDGCCIlib.zip
	${CP} ${WRKDIR}/NETBSDGCCIruntime.zip ${WRKSRC}/../moz/zipped/FREEBSDGCCIruntime.zip

do-build:
	@cd ${WRKSRC}/.. && PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" ./bootstrap
	@cd ${WRKSRC}/.. && PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		tcsh -c 'source FreeBSDEnv.Set && dmake'

do-install:
	@cd ${WRKSRC}/.. && ./setup -r:oo_setup.resp

.include <bsd.port.post.mk>
