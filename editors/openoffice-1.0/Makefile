# New ports collection makefile for: OpenOffice
# Date created:		28 Februar 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice
PORTVERSION=	1.0.0
CATEGORIES+=	editors
MASTER_SITES=	ftp://sunsite.cnlab-switch.ch/mirror/OpenOffice/${PORTVERSION}/ \
		http://niihau.student.utwente.nl/openoffice/${PORTVERSION}/ \
		http://sf1.mirror.openoffice.org/${PORTVERSION}/ \
		ftp://gd.tuwien.ac.at/office/openoffice/${PORTVERSION}/ \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/ \
		http://people.freebsd.org/~mbr/distfiles/
DISTFILES=	OOo_${PORTVERSION}_source.tar.bz2 gpc231.tar.Z \
		oo_moz1.0RC3_includes.tgz ${MOZILLADIST}

SORT?=	/usr/bin/sort

.include <bsd.port.pre.mk>

#
# configuration for language specific slave ports
#
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=	${LANG_PKGNAME}-

#
# LANG_CONFIGURE_ARG is missing for the german port
#
.if defined(LANG_EXT) && ${LANG_EXT}!=49
CONFIGURE_ARGS+=	--with-lang=${LANG_CONFIGURE_ARG},ENUS
.endif

INSTALLATION_BASEDIR=	OpenOffice.org1.0

.if exists(${.CURDIR}/pkg-comment)
COMMENT=	${.CURDIR}/pkg-comment
.endif

.if exists(${.CURDIR}/pkg-descr)
DESCR=	${.CURDIR}/pkg-descr
.endif
.endif

.if !defined(LANG_EXT)
LANG_EXT=01
.endif

.if ${OSVERSION} > 500000
#
# OO is still broken with the system gcc on CURRENT.
#
.if !defined(USE_GCC)
USE_GCC=3.1
.endif
.if defined(USE_GCC) && ${USE_GCC} == 3.1
#
# We depend on the port. System g++ is broken at the moment.
#
BUILD_DEPENDS+= gcc31:${PORTSDIR}/lang/gcc31
CC=		gcc31
CXX=		g++31
.endif
.if defined(USE_GCC) && ${USE_GCC} == 2.95
MOZILLADIST=	oo_moz1.0RC3_${ARCH}_FreeBSD-5-gcc2.95-ports.tar.gz
.else
MOZILLADIST=	oo_moz1.0RC3_${ARCH}_FreeBSD-5-gcc3.1-system.tar.gz
.endif
.else
.if defined(USE_GCC) && ${USE_GCC} == 3.1
MOZILLADIST=	oo_moz1.0RC3_${ARCH}_FreeBSD-4-gcc3.1-ports.tar.gz
.else
MOZILLADIST=	oo_moz1.0RC3_${ARCH}_FreeBSD-4-gcc2.95-system.tar.gz
.endif
.endif

EXTRACT_ONLY=	OOo_${PORTVERSION}_source.tar.bz2

MAINTAINER=	openoffice@FreeBSD.org
.if !defined(USE_GCC)
BUILD_DEPENDS=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
.endif
BUILD_DEPENDS+= zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+= ${JAVAVM}:${PORTSDIR}/java/jdk13
BUILD_DEPENDS+=	imake:${PORTSDIR}/devel/imake-4
.if !defined(DISPLAY)
BUILD_DEPENDS+= Xvfb:${PORTSDIR}/x11-servers/XFree86-4-VirtualFramebufferServer
.endif
LIB_DEPENDS+=	pth.14:${PORTSDIR}/devel/pth

USE_PERL5=	yes
USE_XLIB=	yes
USE_BZIP2=	yes
USE_BISON=	yes
USE_GMAKE=	yes
EXTRACT_BEFORE_ARGS_R= -dc
EXTRACT_AFTER_ARGS_R= | ${TAR} -xf -
EXTRACT_CMD_R= ${GZIP_CMD}
EXTRACT_REST=	gpc231.tar.Z ${MOZILLADIST} oo_moz1.0RC3_includes.tgz

JDK13DIR?=      ${LOCALBASE}/jdk1.3.1
JAVAVM=         ${JDK13DIR}/bin/java

GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
WRKSRC=	${WRKDIR}/oo_1.0_src/config_office
LD_PATH1=	${WRKSRC}/../vos/unxfbsd.pro/lib/:${WRKSRC}/../ucbhelper/unxfbsd.pro/lib/
LD_PATH=	${LD_PATH1}:${WRKSRC}/../solver/641/unxfbsd.pro/lib/
.if defined(WITH_DEBUG)
DMAKE=		dmake debug="true"
.else
DMAKE=		dmake strip="true"
.endif

.if !defined(DISPLAY)
DISPLAYHACK=localhost:1001
.endif

CONFIGURE_ENV=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
			PTHREAD_LIBS=${PTHREAD_LIBS}

CONFIGURE_ARGS+=	--with-jdk-home=${JDK13DIR} \
			--with-os-version=${OSVERSION}

.if !defined(USE_GCC)
CONFIGURE_ARGS+=	--with-stlport4-home=${PREFIX}
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(USE_GCC) && (${USE_GCC} == 3.1 || ${USE_GCC} == 3.2)
CONFIGURE_ARGS+=	--enable-gcc3
.endif

.if ${OSVERSION} > 500000 && !defined(USE_GCC)
CONFIGURE_ARGS+=	--enable-gcc3
.endif

pre-fetch:
.if ${OSVERSION} < 460001
	@${ECHO}
	@${ECHO} OO setup is broken on STABLE < 4.6
	@${ECHO} including 4.6 RELEASE.
	@${ECHO} You'll need a system patch to solve
	@${ECHO}
	@${ECHO} this problem:
	@${ECHO}
	@${ECHO} http://people.freebsd.org/~mbr/patches/rtld-elf.diff
	@${ECHO}
.endif
.if ${OSVERSION} < 500000 
	@${ECHO}
	@${ECHO} OO.org build and also OO.org itself
	@${ECHO} can deadlock. You can work around
	@${ECHO} this problem with this patch:
	@${ECHO}
	@${ECHO} http://people.freebsd.org/~mbr/patches/rtld-elf-patch2.diff
	@${ECHO}
	@${ECHO}
.endif
.if !defined(USE_GCC) || !defined(WITH_DEBUG)
	@${ECHO}
	@${ECHO} OPTIONS:
.endif
.if !defined(USE_GCC)
	@${ECHO}
	@${ECHO} You can compile OO with different
	@${ECHO} gcc compiler versions:
	@${ECHO}
	@${ECHO} Add USE_GCC=2.95 or USE_GCC=3.1
	@${ECHO} to compile openoffice with your
	@${ECHO} prefered compiler.
.endif
.if !defined(WITH_DEBUG)
	@${ECHO}
	@${ECHO} You can compile OO with debug symbols
	@${ECHO} if you call make with WITH_DEBUG=YES
.endif
.if ${OSVERSION} < 450002
	@${ECHO}
	@${ECHO} OS-VERSION ${OSVERSION} too low
	@${ECHO}
	@${ECHO} OO need some important libc_r and
	@${ECHO} gcc fixes to build. Please upgrade to 4.6
	@${ECHO} RELEASE or 4.6 STABLE.
	@${FALSE}
.endif
	@${ECHO}
	@${ECHO} NOTICE:
	@${ECHO}
	@${ECHO} To build Openoffice, you should have a lot
.if defined(WITH_DEBUG)
	@${ECHO} of free diskspace \(~ 8GB\) and you should
.else
	@${ECHO} of free diskspace \(~ 4GB\) and you should
.endif
	@${ECHO} be an experienced port builder. This port
	@${ECHO} has beta quality and does not yet work as
	@${ECHO} stable as it should.
	@${ECHO}
.if (defined(USE_GCC) && ${USE_GCC} == 2.95) || \
    (${OSVERSION} < 500000 && !defined(USE_GCC))
	@${ECHO} KERNEL CONFIGURATION:
	@${ECHO}
	@${ECHO} Openoffice needs a larger stack- and
	@${ECHO} datasize to build. Check your limit
	@${ECHO} settings and and put this in /boot/loader.conf
	@${ECHO} if neccessary:
	@${ECHO} 
	@${ECHO} kern.maxdsiz=\"1073741824\"
	@${ECHO} kern.maxssiz=\"268435456\"
.endif
.if !exists(/usr/include/langinfo.h)
	@${ECHO}
	@${ECHO} langinfo.h is missing !
	@${ECHO}
	@${ECHO} Please upgrade to 4.6 RELEASE or
	@${ECHO} 4.6 STABLE.
	@${ECHO}
	@${FALSE}
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
	@${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/../external/gpc/
	@${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/../external/gpc/
	@${CP} ${WRKDIR}/FREEBSDGCCIinc.zip ${WRKSRC}/../moz/zipped/
	@${CP} ${WRKDIR}/FREEBSDGCCIlib.zip ${WRKSRC}/../moz/zipped/
	@${CP} ${WRKDIR}/FREEBSDGCCIruntime.zip ${WRKSRC}/../moz/zipped/

post-patch:
.if defined(WITH_DEBUG)
	@if [ "`echo ${PATCHDIR}/debugpatch-*`" != "${PATCHDIR}/debugpatch-*" ]; then \
		${ECHO_MSG} "===>  Applying additional debug ${OPSYS} patches for ${PKGNAME}" ; \
		PATCHES_APPLIED="" ; \
		for i in ${PATCHDIR}/debugpatch-*; do \
			case $$i in \
				*.orig|*.rej|*~) \
					${ECHO_MSG} "===>   Ignoring patchfile $$i" ; \
					;; \
				*) \
					if [ ${PATCH_DEBUG_TMP} = yes ]; then \
						${ECHO_MSG} "===>   Applying ${OPSYS} patch $$i" ; \
					fi; \
					if ${PATCH} ${PATCH_ARGS} < $$i ; then \
						PATCHES_APPLIED="$$PATCHES_APPLIED $$i" ; \
					else \
						${ECHO_MSG} `${ECHO_CMD} ">> Patch $$i failed to apply cleanly." | ${SED} "s|${PATCHDIR}/||"` ; \
						if [ x"$$PATCHES_APPLIED" != x"" ]; then \
							${ECHO_MSG} `${ECHO_CMD} ">> Patch(es) $$PATCHES_APPLIED applied cleanly." | ${SED} "s|${PATCHDIR}/||g"` ; \
						fi; \
						${FALSE} ; \
					fi; \
					;; \
			esac; \
		done; \
	fi;
.endif
	@${ECHO_MSG} "===>  Find old malloc.h defines and fix them in ${PKGNAME} source"
	@${FIND} ${WRKSRC}/.. | ${EGREP} "\.(cxx|h|c)$$" | ${XARGS} \
		${PERL} -pi -e "s|<malloc.h>|<stdlib.h>|g"

do-build:
.if exists(${WRKDIR}/.Xvfb.pid)
	@${CAT} ${WRKDIR}/.Xvfb.pid | xargs kill
        @${RM} -f ${WRKDIR}/.Xvfb.pid
.endif
.if !defined(DISPLAY)
	#
	# This is a UGLY hack to not have to specify a X-Display.
	#
	${X11BASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5
.endif
	@cd ${WRKSRC}/.. && PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" ./bootstrap
.if !defined(DISPLAY)
	@cd ${WRKSRC}/.. && DISPLAY=${DISPLAYHACK} PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		tcsh -c 'source FreeBSDEnv.Set && ${DMAKE}'
	@${CAT} ${WRKDIR}/.Xvfb.pid | xargs kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.else
	@cd ${WRKSRC}/.. && DISPLAY=${DISPLAY} PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		tcsh -c 'source FreeBSDEnv.Set && ${DMAKE}'
.endif
.if defined(LANG_PKGNAME)
	@cd ${WRKSRC}/.. && PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		tcsh -c 'source FreeBSDEnv.Set && cd instsetoo/util && ${DMAKE} LANGEXT=${LANGEXT}'
.endif

pre-install:
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#g' < ${FILESDIR}/oo_setup.resp \
	    > ${WRKSRC}/../instsetoo/unxfbsd.pro/${LANG_EXT}/normal/oo_setup.resp

do-install:
.if !defined(DISPLAY)
	#
	# UGLY hack to not have to specify a X-Display.
	#
	${X11BASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" LD_LIBRARY_PATH=${LD_PATH} \
		TEMP=${WRKDIR} DISPLAY=${DISPLAYHACK} \
		${WRKSRC}/../instsetoo/*.pro/${LANG_EXT}/normal/setup -r:oo_setup.resp
	@${CAT} ${WRKDIR}/.Xvfb.pid | xargs kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.else
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" LD_LIBRARY_PATH=${LD_PATH} \
		TEMP=${WRKDIR} DISPLAY=${DISPLAY} \
		${WRKSRC}/../instsetoo/*.pro/${LANG_EXT}/normal/setup -r:oo_setup.resp
.endif

install-user:
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" \
		${PREFIX}/OpenOffice.org1.0/program/setup

# configuration for language specific slave ports
.if defined(LANG_PKGNAME)
post-install:
	@cd ${PREFIX} && ${FIND} -s ${INSTALLATION_BASEDIR} -type f > ${TMPPLIST}
	@cd ${PREFIX} && ${FIND} -s ${INSTALLATION_BASEDIR} -type d > ${WRKDIR}/dir.tmp
	@${SORT} -r ${WRKDIR}/dir.tmp | ${XARGS} -n 1 ${ECHO_CMD} @dirrm >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
