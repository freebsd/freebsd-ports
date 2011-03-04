# ex:ts=8
# Ports collection makefile for:	gcc45
# Date created:				2009-04-05
# Whom:					Gerald Pfeifer <gerald@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	4.5.3.20110303
CATEGORIES=	lang java
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	snapshots/${VERSIONSTRING}
DISTFILES=	gcc-core-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-fortran-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-g++-${VERSIONSTRING}${EXTRACT_SUFX}

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	GNU Compiler Collection 4.5

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		mpfr.4:${PORTSDIR}/math/mpfr \
		mpc.2:${PORTSDIR}/math/mpc
RUN_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils

.if defined(MAINTAINER_MODE)
DISTFILES+=	gcc-testsuite-${VERSIONSTRING}${EXTRACT_SUFX}
BUILD_DEPENDS+=	runtest:${PORTSDIR}/misc/dejagnu
.endif

VERSIONSTRING=	${PORTVERSION:C/([0-9]+\.[0-9]+).*\.([0-9]+)/\1-\2/}
SUFFIX=		${PORTVERSION:C/([0-9]+).([0-9]+).*/\1\2/}
LATEST_LINK=	gcc${SUFFIX}${PKGNAMESUFFIX}
ONLY_FOR_ARCHS=	amd64 i386 ia64 sparc64
USE_BINUTILS=	yes
USE_BISON=	build
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_PERL5_BUILD=yes
MAKE_JOBS_SAFE=	yes

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:S/${WRKDIR}\///}/configure

OPTIONS=	LTO	"Enable link-time optimizations (LTO)"	off \
		JAVA	"Enable the Java frontend (i386 and amd64 only)"	on

.include <bsd.port.pre.mk>

.if defined(WITH_LTO)
LIB_DEPENDS+=	elf.0:${PORTSDIR}/devel/libelf
CONFIGURE_ARGS+=	--enable-lto=yes \
			--with-libelf=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--enable-lto=no
.endif

.if ${ARCH} != i386 && ${ARCH} != amd64
WITHOUT_JAVA=	yes
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

SRCDIR=		${WRKDIR}/gcc-${VERSIONSTRING}
WRKSRC=		${WRKDIR}/build
TARGLIB=	${PREFIX}/lib/gcc${SUFFIX}
LIBEXEC=	${PREFIX}/libexec/gcc${SUFFIX}
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=--disable-nls \
		--libdir=${TARGLIB} \
		--libexecdir=${LIBEXEC} \
		--program-suffix=${SUFFIX} \
		--with-as=${LOCALBASE}/bin/as \
		--with-gmp=${LOCALBASE} \
		--with-gxx-include-dir=${TARGLIB}/include/c++/ \
		--with-ld=${LOCALBASE}/bin/ld \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-system-zlib
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
ALL_TARGET=	bootstrap-lean
USE_LDCONFIG=	${TARGLIB}
PLIST_SUB=	GCC_VER=${PORTVERSION:C/(.+)\.[0-9]+/\1/} \
		GNU_HOST=${CONFIGURE_TARGET} \
		SUFFIX=${SUFFIX}
MAN1=		cpp${SUFFIX}.1 \
		g++${SUFFIX}.1 \
		gcc${SUFFIX}.1 \
		gcov${SUFFIX}.1 \
		gfortran${SUFFIX}.1
INFO=		gcc${SUFFIX}/cpp \
		gcc${SUFFIX}/cppinternals \
		gcc${SUFFIX}/gcc \
		gcc${SUFFIX}/gccinstall \
		gcc${SUFFIX}/gccint \
		gcc${SUFFIX}/gfortran \
		gcc${SUFFIX}/libgomp

.if ! defined(WITHOUT_JAVA)
ECJ_JAR=	ecj-4.5.jar
MASTER_SITES+=	${MASTER_SITE_SOURCEWARE:S|$|:ecj|}
MASTER_SITE_SUBDIR+=	java/:ecj
DISTFILES+=	gcc-java-${VERSIONSTRING}${EXTRACT_SUFX} \
		${ECJ_JAR}:ecj
EXTRACT_ONLY=	${DISTFILES:S|${ECJ_JAR}:ecj||}
BUILD_DEPENDS+=	${LOCALBASE}/bin/zip:${PORTSDIR}/archivers/zip
EXTRA_PATCHES+=	${FILESDIR}/java-patch-hier
# FIXME: we are currently getting weird build failures with libjava on
# some 4.x and 5.x systems, which the following works around. PR 81788.
CONFIGURE_ARGS+=--disable-rpath --enable-libgcj
MAN1+=		aot-compile${SUFFIX}.1 \
		gappletviewer${SUFFIX}.1 \
		gc-analyze${SUFFIX}.1 \
		gcj${SUFFIX}.1 \
		gcj-dbtool${SUFFIX}.1 \
		gcjh${SUFFIX}.1 \
		gij${SUFFIX}.1 \
		gjar${SUFFIX}.1 \
		gjarsigner${SUFFIX}.1 \
		gjavah${SUFFIX}.1 \
		gjdoc${SUFFIX}.1 \
		gkeytool${SUFFIX}.1 \
		gnative2ascii${SUFFIX}.1 \
		gorbd${SUFFIX}.1 \
		grmic${SUFFIX}.1 \
		grmid${SUFFIX}.1 \
		grmiregistry${SUFFIX}.1 \
		gserialver${SUFFIX}.1 \
		gtnameserv${SUFFIX}.1 \
		jcf-dump${SUFFIX}.1 \
		jv-convert${SUFFIX}.1 \
		rebuild-gcj-db${SUFFIX}.1
MAN3=		ffi${SUFFIX}.3 \
		ffi_call${SUFFIX}.3 \
		ffi_prep_cif${SUFFIX}.3
INFO+=		gcc${SUFFIX}/cp-tools \
		gcc${SUFFIX}/gcj
PLIST_SUB+=	JAVA=""

# Preps the source tree for the gcj build
post-patch::
	@${CP} ${DISTDIR}/${ECJ_JAR} ${SRCDIR}/ecj.jar
.else
CONFIGURE_ARGS+=--disable-libgcj
PLIST_SUB+=	JAVA="@comment "
.endif

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION} for ${OPSYS} ${OSREL}  target=${CONFIGURE_TARGET}"

post-patch::
	@${REINPLACE_CMD} -e 's|\(const char version_string.*\)";|\1 [FreeBSD]";|' \
	    ${SRCDIR}/gcc/version.c

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

full-regression-test: build
	cd ${WRKSRC}; ${GMAKE} -sk check

post-install:
	${RM} -f ${PREFIX}/man/man7/fsf-funding.7 \
	         ${PREFIX}/man/man7/gfdl.7 ${PREFIX}/man/man7/gpl.7
	${RM} -f ${TARGLIB}/*.la
	# Add target libraries and include files to packaging list.
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${TARGLIB:S/^${PREFIX}\///} ${LIBEXEC:S/^${PREFIX}\///} include/gcj include/gnu include/java include/javax
	cd ${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	    ${FIND} $d -type d | ${SORT} -r \
	        | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
