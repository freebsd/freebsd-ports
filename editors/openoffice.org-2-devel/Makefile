# New ports collection makefile for: OpenOffice
# Date created:		28 Februar 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice
PORTVERSION=	642
CATEGORIES=	editors
MASTER_SITES=	ftp://sunsite.cnlab-switch.ch/mirror/OpenOffice/${PORTVERSION}/ \
		http://sf1.mirror.openoffice.org/${PORTVERSION}/ \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/ \
		http://people.freebsd.org/~mbr/distfiles/
DISTFILES=	oo_${PORTVERSION}_src.tar.bz2 gpc231.tar.Z oo_moz095_i386_FreeBSD-4.tar.gz
EXTRACT_ONLY=	oo_${PORTVERSION}_src.tar.bz2

MAINTAINER=	openoffice@FreeBSD.org

# OO needs DISPLAY to be set and working
RESTRICTED=	"No automated build possible"

BUILD_DEPENDS=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
BUILD_DEPENDS+= ${LOCALBASE}/bin/gcc295:${PORTSDIR}/lang/gcc295
BUILD_DEPENDS+= zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+= ${JAVAVM}:${PORTSDIR}/java/jdk13
LIB_DEPENDS+=	pth.14:${PORTSDIR}/devel/pth

BROKEN=		'Work in progress -- does not build yet till the end'

USE_XLIB=	yes
USE_BZIP2=	yes
USE_BISON=	yes
USE_GMAKE=	yes
EXTRACT_BEFORE_ARGS_R= -dc
EXTRACT_AFTER_ARGS_R= | ${TAR} -xf -
EXTRACT_CMD_R= ${GZIP_CMD}
EXTRACT_REST=	gpc231.tar.Z oo_moz095_i386_FreeBSD-4.tar.gz

GCC_VERSION!=	${CC} --version
JDK13DIR?=      ${LOCALBASE}/jdk1.3.1
JAVAVM=         ${JDK13DIR}/bin/java

GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
WRKSRC=	${WRKDIR}/oo_${PORTVERSION}_src/config_office

CONFIGURE_ARGS+=	--with-stlport4-home=${PREFIX} \
			--with-jdk-home=${JDK13DIR} \
			--with-os-version=${OSVERSION}

CONFIGURE_ENV=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
			PTHREAD_LIBS=${PTHREAD_LIBS} \
			CC=gcc295 \
			CXX=g++295

MAKE_ENV=		CC=${CC} CFLAGS=${CFLAGS}

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
	${CP} ${WRKDIR}/FREEBSDGCCIinc.zip ${WRKSRC}/../moz/zipped/
	${CP} ${WRKDIR}/FREEBSDGCCIlib.zip ${WRKSRC}/../moz/zipped/
	${CP} ${WRKDIR}/FREEBSDGCCIruntime.zip ${WRKSRC}/../moz/zipped/

post-patch:
	@${FIND} ${WRKSRC}/.. | ${EGREP} "\.(cxx|h|c)$$" | ${XARGS} \
		${PERL} -pi -e "s|<malloc.h>|<stdlib.h>|g"

do-build:
	@cd ${WRKSRC}/.. && PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" ./bootstrap
	@cd ${WRKSRC}/.. && PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		tcsh -c 'source FreeBSDEnv.Set && dmake'

do-install:
	@cd ${WRKSRC}/.. && ./setup -r:oo_setup.resp

.include <bsd.port.post.mk>
