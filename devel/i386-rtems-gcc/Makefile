# New ports collection makefile for:	i386-rtems-gcc
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	3.2.3
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} \
		${MASTER_SITE_GNU:S/$/:gcc/}
MASTER_SITE_SUBDIR=	newlib \
			${PORTNAME}/${GCCNAME}/:gcc
DISTFILES=		${NEWLIBNAME}.tar.gz \
			${GCCNAME}.tar.gz:gcc
PATCHFILES=	${GCCNAME}-rtems-20030507a.diff \
		${NEWLIBNAME}-rtems-20030605.diff
PATCH_SITES=	ftp://ftp.rtems.com/pub/rtems/snapshots/c_tools/source/ \
		http://rtems.thehousleys.net/

MAINTAINER=	jeh@FreeBSD.org
COMMENT=	FSF C/C++/JAVA-gcc-3.2.3 base-port for RTEMS development

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		"Configure fails on amd64 and sparc64"
.endif

RTEMS_ARCH?=	i386
LCLTARGET=	${RTEMS_ARCH}-rtems

.if ${RTEMS_ARCH} == m68k && ${ARCH} != "i386"
BROKEN=		"Internal compiler error during build on !i386"
.endif

GCCVERSION=	3.2.3
GCCNAME=	gcc-${GCCVERSION}
PLIST_SUB+=	"GCCVERSION=${GCCVERSION}"
NEWLIBNAME=	newlib-1.11.0
PLIST=		${PKGDIR}/pkg-plist.${LCLTARGET}
USE_GETTEXT=	yes

BUILD_DEPENDS=	${LCLTARGET}-as:${PORTSDIR}/devel/${LCLTARGET}-binutils \
		${LCLTARGET}-ld:${PORTSDIR}/devel/${LCLTARGET}-binutils
RUN_DEPENDS=	${LCLTARGET}-as:${PORTSDIR}/devel/${LCLTARGET}-binutils \
		${LCLTARGET}-ld:${PORTSDIR}/devel/${LCLTARGET}-binutils

PKGNAMEPREFIX=	${LCLTARGET}-
WANT_AUTOHEADER_VER=253
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
ALL_TARGET=	all info

CONFIGURE_TARGET?=	--target=${LCLTARGET}
CONFIGURE_ARGS?=	--with-gnu-as --with-gnu-ld --with-newlib --verbose \
			--enable-languages="c,c++,java" \
			--with-libiconv-prefix=${LOCALBASE} \
			--without-included-gettext
CONFIGURE_WRKSRC?=	${WRKDIR}/build-${LCLTARGET}
CONFIGURE_SCRIPT?=	../${GCCNAME}/configure

PATCH_WRKSRC=		${WRKDIR}
PATCH_STRIP=		-p

WITHOUT_CPU_CFLAGS=	yes
MAKE_FLAGS=	LANGUAGES="c c++ java"
MAKE_ENV=	MACHINE_ARCH=${RTEMS_ARCH} NO_CPU_CFLAGS=true

MAN1=		${LCLTARGET}-gcc.1 ${LCLTARGET}-g++.1 ${LCLTARGET}-gcj.1 \
		cpp.1 gcov.1 gcjh.1 jv-scan.1 jcf-dump.1 gij.1 \
		jv-convert.1 rmic.1 rmiregistry.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7
INFO=		${LCLTARGET}-cpp ${LCLTARGET}-cppinternals \
		${LCLTARGET}-gcc ${LCLTARGET}-gccint ${LCLTARGET}-gcj

pre-configure:
	@(cd ${WRKDIR} ; \
	cd ${GCCNAME} ; ${LN} -fs ../${NEWLIBNAME}/newlib . ; \
	cd .. ; \
	${MKDIR} build-${LCLTARGET})
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/gcc/configure

post-patch:
# Change cpp.info to ${LCLTARGET}-cpp.info
	@${REINPLACE_CMD} -e 's|setfilename cpp.info|setfilename ${LCLTARGET}-cpp.info|g' ${WRKSRC}/gcc/doc/*.texi
	@${REINPLACE_CMD} -e 's|(cpp)|(${LCLTARGET}-cpp)|g' ${WRKSRC}/gcc/doc/*.texi
	@${REINPLACE_CMD} -e 's|@file{cpp}|@file{${LCLTARGET}-cpp}|g' ${WRKSRC}/gcc/doc/*.texi
	@${REINPLACE_CMD} -e 's|cpp.info|${LCLTARGET}-cpp.info|g' ${WRKSRC}/gcc/Makefile.in
	@${REINPLACE_CMD} -e 's|cpp.texi|${LCLTARGET}-cpp.texi|g' ${WRKSRC}/gcc/Makefile.in
	@${MV} ${WRKSRC}/gcc/doc/cpp.texi ${WRKSRC}/gcc/doc/${LCLTARGET}-cpp.texi
# special case for included file
	@${REINPLACE_CMD} -e 's|,cpp.info,|,${LCLTARGET}-cpp.info,|g' ${WRKSRC}/gcc/doc/extend.texi
# Change cpp.info to ${LCLTARGET}-cpp.info
	@${REINPLACE_CMD} -e 's|setfilename cppinternals.info|setfilename ${LCLTARGET}-cppinternals.info|g' ${WRKSRC}/gcc/doc/*.texi
	@${REINPLACE_CMD} -e 's|(cppinternals)|(${LCLTARGET}-cppinternals)|g' ${WRKSRC}/gcc/doc/*.texi
	@${REINPLACE_CMD} -e 's|@file{cppinternals}|@file{${LCLTARGET}-cppinternals}|g' ${WRKSRC}/gcc/doc/*.texi
	@${REINPLACE_CMD} -e 's|cppinternals.info|${LCLTARGET}-cppinternals.info|g' ${WRKSRC}/gcc/Makefile.in
	@${REINPLACE_CMD} -e 's|cppinternals.texi|${LCLTARGET}-cppinternals.texi|g' ${WRKSRC}/gcc/Makefile.in
	@${MV} ${WRKSRC}/gcc/doc/cppinternals.texi ${WRKSRC}/gcc/doc/${LCLTARGET}-cppinternals.texi
# Change cpp.info to ${LCLTARGET}-cpp.info
	@${REINPLACE_CMD} -e 's|setfilename gcc.info|setfilename ${LCLTARGET}-gcc.info|g' ${WRKSRC}/gcc/doc/*.texi
	@${REINPLACE_CMD} -e 's|(gcc)|(${LCLTARGET}-gcc)|g' ${WRKSRC}/gcc/doc/*.texi
	@${REINPLACE_CMD} -e 's|@file{gcc}|@file{${LCLTARGET}-gcc}|g' ${WRKSRC}/gcc/doc/*.texi
	@${REINPLACE_CMD} -e 's|gcc.info|${LCLTARGET}-gcc.info|g' ${WRKSRC}/gcc/Makefile.in
	@${REINPLACE_CMD} -e 's|gcc.texi|${LCLTARGET}-gcc.texi|g' ${WRKSRC}/gcc/Makefile.in
	@${MV} ${WRKSRC}/gcc/doc/gcc.texi ${WRKSRC}/gcc/doc/${LCLTARGET}-gcc.texi
# Change cpp.info to ${LCLTARGET}-cpp.info
	@${REINPLACE_CMD} -e 's|setfilename gccint.info|setfilename ${LCLTARGET}-gccint.info|g' ${WRKSRC}/gcc/doc/*.texi
	@${REINPLACE_CMD} -e 's|(gccint)|(${LCLTARGET}-gccint)|g' ${WRKSRC}/gcc/doc/*.texi
	@${REINPLACE_CMD} -e 's|@file{gccint}|@file{${LCLTARGET}-gccint}|g' ${WRKSRC}/gcc/doc/*.texi
	@${REINPLACE_CMD} -e 's|gccint.info|${LCLTARGET}-gccint.info|g' ${WRKSRC}/gcc/Makefile.in
	@${REINPLACE_CMD} -e 's|gccint.texi|${LCLTARGET}-gccint.texi|g' ${WRKSRC}/gcc/Makefile.in
	@${MV} ${WRKSRC}/gcc/doc/gccint.texi ${WRKSRC}/gcc/doc/${LCLTARGET}-gccint.texi
# Change gcj.info to ${LCLTARGET}-gcj.info
	@${REINPLACE_CMD} -e 's|setfilename gcj.info|setfilename ${LCLTARGET}-gcj.info|g' ${WRKSRC}/gcc/java/*.texi
	@${REINPLACE_CMD} -e 's|(gcj)|(${LCLTARGET}-gcj)|g' ${WRKSRC}/gcc/java/*.texi
	@${REINPLACE_CMD} -e 's|@file{gcj}|@file{${LCLTARGET}-gcj}|g' ${WRKSRC}/gcc/java/*.texi
	@${REINPLACE_CMD} -e 's|gcj.info|${LCLTARGET}-gcj.info|g' ${WRKSRC}/gcc/java/Make-lang.in
	@${REINPLACE_CMD} -e 's|gcj.texi|${LCLTARGET}-gcj.texi|g' ${WRKSRC}/gcc/java/Make-lang.in
	@${MV} ${WRKSRC}/gcc/java/gcj.texi ${WRKSRC}/gcc/java/${LCLTARGET}-gcj.texi

do-build:
	@(cd ${WRKDIR}/build-${LCLTARGET} ; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${WRKDIR}/build-${LCLTARGET} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
