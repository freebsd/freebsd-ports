# New ports collection makefile for:    sablevm
# Date created:         		9 July 2002
# Whom:                 		Archie Cobbs <archie@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sablevm
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=sablevm
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-class-library-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-native-library-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	archie@freebsd.org
COMMENT=	Java VM created by McGill University's Sable Research Group

BUILD_DEPENDS=	jikes:${PORTSDIR}/java/jikes
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		ffi.2:${PORTSDIR}/devel/libffi \
		gmp.6:${PORTSDIR}/math/libgmp4 \
		ltdl.4:${PORTSDIR}/devel/libltdl

PATCH_WRKSRC=	${WRKDIR}
PATCH_STRIP=	-p1
USE_LIBTOOL=	yes
LIBTOOLFILES=	${SABLEVMDIR}/configure ${NATIVEDIR}/configure
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}
CONFIGURE_ENV=	CFLAGS="-D__XSI_VISIBLE -D__BSD_VISIBLE -D_P1003_1B_VISIBLE -pthread -I${PREFIX}/include -L${PREFIX}/lib"

.if defined(WITH_GNOMELIBS) || exists(${X11BASE}/include/gnome-1.0/libart_lgpl/art_misc.h)
USE_GNOME=	gnomelibs
PLIST_SUB+=	GNOME:=""
.else
PLIST_SUB+=	GNOME:="@comment "
.endif

# Directories for the three SableVM source components
SABLEVMDIR=	${PORTNAME}-${PORTVERSION}
NATIVEDIR=	${PORTNAME}-native-library-${PORTVERSION}
CLASSESDIR=	${PORTNAME}-class-library-${PORTVERSION}

# Conditionally compile the gnome-dependent stuff
.if !defined(WITH_GNOMELIBS) && !exists(${X11BASE}/include/gnome-1.0/libart_lgpl/art_misc.h)
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-aa ${PATCHDIR}/extra-patch-ab
pre-fetch:
	@${ECHO} ''
	@${ECHO} '***' '                 ' NOTICE
	@${ECHO} '***'
	@${ECHO} '***' You do not seem to have the Gnome libraries installed.
	@${ECHO} '***' Therefore, SableVM will be built without graphics
	@${ECHO} '***' support. If you would like to install the Gnome
	@${ECHO} '***' libraries to include graphics support, hit Control-C
	@${ECHO} '***' now and type \'make WITH_GNOMELIBS=yes\'.
	@${ECHO} '***'
	@${ECHO} ''
	@sleep 3
.endif

# Repair make dependency damage caused by patching 'configure.ac' files
post-patch:
		@for dir in ${SABLEVMDIR}; do \
		    for file in aclocal.m4 configure Makefile.in Makefile; do \
			${ECHO} ${TOUCH} ${WRKDIR}/$${dir}/$${file}; \
			${TOUCH} ${WRKDIR}/$${dir}/$${file}; \
		    done; \
		done

pre-configure:
		@echo "===>    ${NATIVEDIR}"
		@( cd ${.CURDIR} && ${MAKE} do-configure \
		    CONFIGURE_WRKSRC=${WRKDIR}/${NATIVEDIR} \
		    CFLAGS="-I${X11BASE}/include/gtk12 \
			-I${PREFIX}/include/glib12" )
		@echo "===>    ${SABLEVMDIR}"

pre-build:
		@echo "===>    ${NATIVEDIR}"
		@( cd ${.CURDIR} && ${MAKE} do-build \
		    BUILD_WRKSRC=${WRKDIR}/${NATIVEDIR} )
		@echo "===>    ${CLASSESDIR}"
		@cd ${WRKDIR}/${CLASSESDIR}; \
		${MKDIR} classes; \
		${FIND} . | ${GREP} '\.java$$' | ${XARGS} jikes -g \
		    -target 1.1 -d classes \
		    -bootclasspath src:classes -classpath src:classes \
		    -sourcepath src || exit 1; \
		${FIND} resource -type f | cut -d\/ -f2- \
		    | ${AWK} '{print "cp resource/" $$0 " classes/" $$0 }' \
		    | ${SH}; \
		${CHMOD} -R a+rX classes
		@echo "===>    ${SABLEVMDIR}"

pre-install:
		@echo "===>    ${NATIVEDIR}"
		@( cd ${.CURDIR} && ${MAKE} do-install \
		    INSTALL_WRKSRC=${WRKDIR}/${NATIVEDIR} )
		@echo "===>    ${CLASSESDIR}"
		${RM} -rf ${PREFIX}/lib/sablevm/classes-${PORTVERSION}
		${CP} -R ${WRKDIR}/${CLASSESDIR}/classes \
		    ${PREFIX}/lib/sablevm/classes-${PORTVERSION}
		${CP} -R ${WRKDIR}/${CLASSESDIR}/resource \
		    ${PREFIX}/lib/sablevm/classes-${PORTVERSION}
		${MKDIR} -p ${PREFIX}/lib/sablevm/lib/security
		${ECHO} security.provider.1=gnu.java.security.provider.Gnu \
		    > ${PREFIX}/lib/sablevm/lib/security/classpath.security
		@echo "===>    ${SABLEVMDIR}"

.include <bsd.port.mk>
