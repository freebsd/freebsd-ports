# New ports collection makefile for:    sablevm
# Date created:         		9 July 2002
# Whom:                 		Archie Cobbs <archie@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sablevm
PORTVERSION=	1.0.3
CATEGORIES=	java
MASTER_SITES=	http://unc.dl.sourceforge.net/sablevm/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-class-library-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-native-library-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	archie@freebsd.org

BUILD_DEPENDS=	jikes:${PORTSDIR}/java/jikes
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		ffi.2:${PORTSDIR}/devel/libffi \
		gmp.6:${PORTSDIR}/math/libgmp4 \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

PATCH_WRKSRC=	${WRKDIR}
PATCH_STRIP=	-p1
USE_LIBTOOL=	yes
LIBTOOLFILES=	${SABLEVMDIR}/configure ${NATIVEDIR}/configure
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}
# Uncomment to force gnome dependency
#USE_GNOMELIBS=	yes

# Directories for the three SableVM source components
SABLEVMDIR=	${PORTNAME}-${PORTVERSION}
NATIVEDIR=	${PORTNAME}-native-library-${PORTVERSION}
CLASSESDIR=	${PORTNAME}-class-library-${PORTVERSION}

# Conditionally compile the gnome-dependent stuff
.if !defined(USE_GNOMELIBS) && !exists(${X11BASE}/libart_lgpl/art_misc.h)
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-aa ${PATCHDIR}/extra-patch-ab
pre-fetch:
	@${ECHO} ''
	@${ECHO} '***' '                 ' NOTICE
	@${ECHO} '***'
	@${ECHO} '***' You do not seem to have the Gnome libraries installed.
	@${ECHO} '***' Therefore, SableVM will be built without graphics
	@${ECHO} '***' support. If you would like to install the Gnome
	@${ECHO} '***' libraries for include graphics support, hit Control-C
	@${ECHO} '***' now and type \'make USE_GNOMELIBS=yes\'.
	@${ECHO} ''
	@sleep 3
.endif

# Repair make dependency damage caused by patching 'configure.ac' files
post-patch:
		@for dir in ${SABLEVMDIR}; do \
		    for file in aclocal.m4 configure Makefile.in Makefile; do \
			${ECHO} ${TOUCH} ${WRKDIR}/$${dir}/$${file}; \
			touch ${WRKDIR}/$${dir}/$${file}; \
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
		find . | ${GREP} '\.java$$' | xargs jikes -g -d classes \
		    -bootclasspath src:classes -classpath src:classes \
		    -sourcepath src || exit 1; \
		find resource -type f | cut -d\/ -f2- \
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
		@echo "===>    ${SABLEVMDIR}"

.include <bsd.port.mk>
