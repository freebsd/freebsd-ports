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

BROKEN=		'Work in progress -- does build - but does not start yet'

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
.if ${GCC_VERSION}!="2.95.2" && ${GCC_VERSION}!="2.95.3" && ${GCC_VERSION}!="2.95.4"
	@ ${ECHO}
	@ ${ECHO} Openoffice requires gcc 2.95.2 or better
	@ ${ECHO}
	@ ${FALSE}
.endif
pre-extract:
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
	${SH} -c "cd ${WRKSRC}/../instsetoo/*.pro/01/normal && \
		${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
		< ${FILESDIR}/oo_setup.resp > oo_setup.resp"

do-install:
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" LD_LIBRARY_PATH=${LD_PATH} \
		TEMP=${WRKDIR} DISPLAY=${DISPLAY} \
		${WRKSRC}/../instsetoo/*.pro/01/normal/setup -r:oo_setup.resp

.include <bsd.port.post.mk>
