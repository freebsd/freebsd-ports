# New ports collection makefile for: OpenOffice
# Date created:		28 Februar 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice
PORTVERSION=	1.0.0
CATEGORIES=	editors
MASTER_SITES=	ftp://sunsite.cnlab-switch.ch/mirror/OpenOffice/${PORTVERSION}/ \
		http://niihau.student.utwente.nl/openoffice/${PORTVERSION}/ \
		http://sf1.mirror.openoffice.org/${PORTVERSION}/ \
		ftp://gd.tuwien.ac.at/office/openoffice/${PORTVERSION}/ \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/ \
		http://people.freebsd.org/~mbr/distfiles/
DISTFILES=	OOo_${PORTVERSION}_source.tar.bz2 gpc231.tar.Z

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
.if defined(USE_GCC) && ${USE_GCC} == 2.95
DISTFILES+=	oo_moz1.0RC3_${ARCH}_FreeBSD-5-gcc2.95-ports.tar.gz
.else
DISTFILES+=	oo_moz1.0RC3_${ARCH}_FreeBSD-5-gcc3.1-system.gz
.endif
.else
.if defined(USE_GCC) && ${USE_GCC} == 3.1
DISTFILES+=	oo_moz1.0RC3_${ARCH}_FreeBSD-4-gcc3.1-ports.tar.gz
.else
DISTFILES+=	oo_moz1.0RC3_${ARCH}_FreeBSD-4-gcc2.95-system.tar.gz
.endif
.endif
EXTRACT_ONLY=	OOo_${PORTVERSION}_source.tar.bz2

MAINTAINER=	mbr@FreeBSD.org
.if ${OSVERSION} < 500000 && !defined(USE_GCC)
BUILD_DEPENDS=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
.endif
BUILD_DEPENDS+= zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+= ${JAVAVM}:${PORTSDIR}/java/jdk13
BUILD_DEPENDS+=	imake:${PORTSDIR}/devel/imake-4
LIB_DEPENDS+=	pth.14:${PORTSDIR}/devel/pth

USE_PERL5=	yes
USE_XLIB=	yes
USE_BZIP2=	yes
USE_BISON=	yes
USE_GMAKE=	yes
EXTRACT_BEFORE_ARGS_R= -dc
EXTRACT_AFTER_ARGS_R= | ${TAR} -xf -
EXTRACT_CMD_R= ${GZIP_CMD}
.if ${OSVERSION} > 500000
.if defined(USE_GCC) && ${USE_GCC} == 2.95
EXTRACT_REST=	gpc231.tar.Z oo_moz1.0RC3_${ARCH}_FreeBSD-5-gcc2.95-ports.tar.gz
.else
EXTRACT_REST=	gpc231.tar.Z oo_moz1.0RC3_${ARCH}_FreeBSD-5-gcc3.1-system.gz
.endif
.else
.if defined(USE_GCC) && ${USE_GCC} == 3.1
EXTRACT_REST=	gpc231.tar.Z oo_moz1.0RC3_${ARCH}_FreeBSD-4-gcc3.1-ports.tar.gz
.else
EXTRACT_REST=	gpc231.tar.Z oo_moz1.0RC3_${ARCH}_FreeBSD-4-gcc2.95-system.tar.gz
.endif
.endif

JDK13DIR?=      ${LOCALBASE}/jdk1.3.1
JAVAVM=         ${JDK13DIR}/bin/java

GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
WRKSRC=	${WRKDIR}/oo_1.0_src/config_office
LD_PATH1=	${WRKSRC}/../vos/unxfbsd.pro/lib/:${WRKSRC}/../ucbhelper/unxfbsd.pro/lib/
LD_PATH=	${LD_PATH1}:${WRKSRC}/../solver/641/unxfbsd.pro/lib

CONFIGURE_ENV=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
			PTHREAD_LIBS=${PTHREAD_LIBS}

CONFIGURE_ARGS+=	--with-jdk-home=${JDK13DIR} \
			--with-os-version=${OSVERSION}

.if !defined(USE_GCC)
CONFIGURE_ARGS+=	--with-stlport4-home=${PREFIX}
.endif

.if defined(USE_GCC) && (${USE_GCC} == 3.1 || ${USE_GCC} == 3.2)
CONFIGURE_ARGS+=	--enable-gcc3
.endif

.if ${OSVERSION} > 500000 && !defined(USE_GCC)
CONFIGURE_ARGS+=	--enable-gcc3
.endif

pre-fetch:
.if !defined(USE_GCC)
	@${ECHO}
	@${ECHO} You can compile openoffice with different
	@${ECHO} gcc compiler versions:
	@${ECHO}
	@${ECHO} Use: USE_GCC=2.95 or USE_GCC=3.1
	@${ECHO} to compile openoffice with your
	@${ECHO} prefered compiler.
	@${ECHO}
.endif
.if ${OSVERSION} < 450002
	@${ECHO}
	@${ECHO} OS-VERSION ${OSVERSION} too low
	@${ECHO}
	@${ECHO} Openoffice need some important libc_r and
	@${ECHO} gcc fixes to build. Please upgrade to 4.6
	@${ECHO} PRE-RELEASE or RELEASE.
	@${FALSE}
.endif
	@${ECHO}
	@${ECHO} NOTICE:
	@${ECHO}
	@${ECHO} To build Openoffice, you should have a lot
	@${ECHO} of free diskspace \(~ 6GB\) and you should
	@${ECHO} be an experienced port builder. This port
	@${ECHO} has beta quality and does not yet work as
	@${ECHO} stable as it should.
	@${ECHO}
pre-extract:
	@${ECHO}
	@${ECHO} Openoffice needs a larger stack- and
	@${ECHO} datasize to build. Check your limit
	@${ECHO} settings and add this to your KERNEL
	@${ECHO} configuration if necessary:
	@${ECHO}
	@${ECHO} options	MAXDSIZ=\"\(1024*1024*1024\)\"
	@${ECHO} options	MAXSSIZ=\"\(256*1024*1024\)\"
	@${ECHO}
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} "Cannot open display; please check your DISPLAY variable."
	@ ${ECHO}
	@ ${FALSE}
.endif
.if !exists(/usr/include/langinfo.h)
	@${ECHO}
	@${ECHO} langinfo.h is missing !
	@${ECHO}
	@${ECHO} Please upgrade to 4.5 STABLE or
	@${ECHO} 4.6 RELEASE.
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

pre-install:
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#g' < ${FILESDIR}/oo_setup.resp \
	    > ${WRKSRC}/../instsetoo/unxfbsd.pro/01/normal/oo_setup.resp

do-install:
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" LD_LIBRARY_PATH=${LD_PATH} \
		TEMP=${WRKDIR} DISPLAY=${DISPLAY} \
		${WRKSRC}/../instsetoo/*.pro/01/normal/setup -r:oo_setup.resp

install-user:
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" \
		${PREFIX}/OpenOffice.org1.0/program/setup

.include <bsd.port.post.mk>
