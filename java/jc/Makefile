# New ports collection makefile for:    jc
# Date created:         		20 Feb 2004
# Whom:                 		Archie Cobbs <archie@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	jc
PORTVERSION=	1.2.2
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_GNU:S/$/:CLASSPATH/g}
MASTER_SITE_SUBDIR=jcvm/ classpath/:CLASSPATH
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		classpath-${CLASSPATHVERSION}${EXTRACT_SUFX}:CLASSPATH
DIST_SUBDIR=	jcvm

MAINTAINER=	archie@freebsd.org
COMMENT=	JVM that converts class files to C source and compiles them with GCC

BUILD_DEPENDS=	jikes:${PORTSDIR}/java/jikes \
		zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		ffi.2:${PORTSDIR}/devel/libffi \
		gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20 \
		art_lgpl_2:${PORTSDIR}/graphics/libart_lgpl2

USE_LIBTOOL_VER=15
LIBTOOLFILES=	${CLASSPATHDIR}/configure
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${PREFIX}/include" \
		LDFLAGS="${LDFLAGS} -L${PREFIX}/lib"
PATCH_WRKSRC=	${WRKDIR}
INFO=		jc
ONLY_FOR_ARCHS=	i386

# Directories for the two source components
JCDIR=		${PORTNAME}-${PORTVERSION}
CLASSPATHDIR=	classpath-${CLASSPATHVERSION}

# Classpath version
CLASSPATHVERSION=0.10

# Jikes version expected
JIKESVERSION=	1.21

# Configure args
CLASSPATH_CONF=	--prefix=${PREFIX}/jc --enable-jni --with-jikes
CONFIGURE_ARGS=	--prefix=${PREFIX}

pre-configure:
		@${ECHO} "===>    Configuring ${CLASSPATHDIR}"
		@( cd ${.CURDIR} && ${MAKE} do-configure \
		    CONFIGURE_WRKSRC=${WRKDIR}/${CLASSPATHDIR} \
		    CONFIGURE_ARGS="${CLASSPATH_CONF}" )
		@${ECHO} "===>    Configuring ${JCDIR}"

pre-build:
		@JIKESVER=`jikes -version 2>&1 | ${GREP} -wi version | ${SED} -E 's/^.*[Vv]ersion[[:space:]]+([0-9.]+).*$$/\1/g'`; \
		if [ "$${JIKESVER}" != "" -a "$${JIKESVER}" != "${JIKESVERSION}" ]; then \
		    ${ECHO} ''; \
		    ${ECHO} '***' '                    ' WARNING; \
		    ${ECHO} '***'; \
		    ${ECHO} '***' You have jikes version $${JIKESVER} installed instead of version ${JIKESVERSION}.; \
		    ${ECHO} '***' This will cause JC to have to bootstrap re-generate all JC and; \
		    ${ECHO} '***' Classpath source files when it first runs, which requires that; \
		    ${ECHO} '***' the JDK \(or some other JVM\) be installed. To avoid this, hit; \
		    ${ECHO} '***' CTRL-C now and install jikes version ${JIKESVERSION}.; \
		    ${ECHO} '***' ; \
		    ${ECHO} ''; \
		    sleep 10; \
		fi
		@${ECHO} "===>    Building ${CLASSPATHDIR}"
		@( cd ${.CURDIR} && ${MAKE} do-build \
		    BUILD_WRKSRC=${WRKDIR}/${CLASSPATHDIR} )
		@${ECHO} "===>    Building ${JCDIR}"

pre-install:
		@${ECHO} "===>    Installing ${CLASSPATHDIR}"
		@( cd ${.CURDIR} && ${MAKE} do-install \
		    INSTALL_WRKSRC=${WRKDIR}/${CLASSPATHDIR} )
		@${ECHO} "===>    Installing ${JCDIR}"

.include <bsd.port.mk>
