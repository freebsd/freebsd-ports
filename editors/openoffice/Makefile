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
DISTFILES=	OOo_${PORTVERSION}_source.tar.bz2 gpc231.tar.Z \
		oo_moz1.0RC2_i386_FreeBSD-4.tar.gz
EXTRACT_ONLY=	OOo_${PORTVERSION}_source.tar.bz2

MAINTAINER=	mbr@FreeBSD.org
BUILD_DEPENDS=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
BUILD_DEPENDS+= zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+= ${JAVAVM}:${PORTSDIR}/java/jdk13
LIB_DEPENDS+=	pth.14:${PORTSDIR}/devel/pth

USE_XLIB=	yes
USE_BZIP2=	yes
USE_BISON=	yes
USE_GMAKE=	yes
EXTRACT_BEFORE_ARGS_R= -dc
EXTRACT_AFTER_ARGS_R= | ${TAR} -xf -
EXTRACT_CMD_R= ${GZIP_CMD}
EXTRACT_REST=	gpc231.tar.Z oo_moz1.0RC2_i386_FreeBSD-4.tar.gz

GCC_VERSION!=	${CC} --version
JDK13DIR?=      ${LOCALBASE}/jdk1.3.1
JAVAVM=         ${JDK13DIR}/bin/java

GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
WRKSRC=	${WRKDIR}/oo_1.0_src/config_office
LD_PATH=	${WRKSRC}/../vos/unxfbsd.pro/lib:${WRKSRC}/../ucbhelper/unxfbsd.pro/lib

CONFIGURE_ARGS+=	--with-stlport4-home=${PREFIX} \
			--with-jdk-home=${JDK13DIR} \
			--with-os-version=${OSVERSION}

CONFIGURE_ENV=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
			PTHREAD_LIBS=${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

pre-fetch:
.if ${OSVERSION} > 500000
	@${ECHO}
	@${ECHO} OS-VERSION ${OSVERSION} too high
	@${ECHO}
	@${ECHO} Openoffice is currently broken on CURRENT and does
	@${ECHO} not yet work with GCC 3.1
	@${ECHO}
	@${ECHO} It also does not work without some important
	@${ECHO} libc_r gcc fixes.
	@${ECHO}
	@${FALSE}
.endif
.if ${OSVERSION} < 450005
	@${ECHO}
	@${ECHO} OS-VERSION ${OSVERSION} too low
	@${ECHO}
	@${ECHO} Openoffice need some important libc_r and
	@${ECHO} gcc fixes to build. Please upgrade to 4.6
	@${ECHO} PRE-RELEASE or RELEASE.
	@${FALSE}
.endif
.if ${GCC_VERSION}!="2.95.2" && ${GCC_VERSION}!="2.95.3" && ${GCC_VERSION}!="2.95.4"
	@ ${ECHO}
	@ ${ECHO} Openoffice requires gcc 2.95.2 or better
	@ ${ECHO}
	@ ${FALSE}
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
	@ ${ECHO} Cannot open display; please check your DISPLAY variable.
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
