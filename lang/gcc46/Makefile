# Created by: Gerald Pfeifer <gerald@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	4.6.4
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	lang java
MASTER_SITES=	GCC/releases/gcc-${DISTVERSION}
PKGNAMESUFFIX=	${SUFFIX}

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	GNU Compiler Collection 4.6

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils

.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	runtest:misc/dejagnu
.endif

CPE_VENDOR=	gnu

# DISTVERSION relates to downloads, GCC_VERSION and SUFFIX to names
# of executables and directories once installed.
DISTVERSION=	${PORTVERSION}
GCC_VERSION=	${PORTVERSION:C/(.+)\.[0-9]{8}/\1/}
SUFFIX=		${PORTVERSION:C/([0-9]+).([0-9]+).*/\1\2/}
ONLY_FOR_ARCHS=	amd64 i386 ia64 powerpc sparc64
USES=		cpe gmake iconv libtool makeinfo perl5 tar:bzip2
USE_BINUTILS=	yes
USE_PERL5=	build
SSP_UNSAFE=	yes

OPTIONS_DEFINE=		BOOTSTRAP
OPTIONS_DEFINE_i386=	JAVA
OPTIONS_DEFINE_amd64=	JAVA
OPTIONS_DEFAULT_i386=	JAVA
OPTIONS_DEFAULT_amd64=	JAVA
OPTIONS_EXCLUDE_DragonFly=	JAVA
BOOTSTRAP_DESC=		Build using a full bootstrap

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-${OPSYS:tl}${OSREL}
.endif

LANGUAGES:=	c,c++,objc,fortran
TARGLIB=	${PREFIX}/lib/gcc${SUFFIX}
LIBEXEC=	${PREFIX}/libexec/gcc${SUFFIX}
GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
.if empty(PORT_OPTIONS:MBOOTSTRAP)
CONFIGURE_ARGS+=--disable-bootstrap
.else
CONFIGURE_ARGS+=--with-build-config=bootstrap-debug
ALL_TARGET=	bootstrap-lean
.endif
CONFIGURE_ARGS+=--disable-nls \
		--libdir=${TARGLIB} \
		--libexecdir=${LIBEXEC} \
		--program-suffix=${SUFFIX} \
		--with-as=${LOCALBASE}/bin/as \
		--with-gmp=${LOCALBASE} \
		--with-gxx-include-dir=${TARGLIB}/include/c++/ \
		--with-ld=${LOCALBASE}/bin/ld \
		${ICONV_CONFIGURE_ARG} \
		--with-pkgversion="FreeBSD Ports Collection" \
		--with-system-zlib
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
USE_LDCONFIG=	${TARGLIB}
PLIST_SUB=	GCC_VERSION=${GCC_VERSION} \
		GNU_HOST=${CONFIGURE_TARGET} \
		SUFFIX=${SUFFIX}
INFO=		gcc${SUFFIX}/cpp \
		gcc${SUFFIX}/cppinternals \
		gcc${SUFFIX}/gcc \
		gcc${SUFFIX}/gccinstall \
		gcc${SUFFIX}/gccint \
		gcc${SUFFIX}/gfortran \
		gcc${SUFFIX}/libgomp
# Release tarballs (as opposed to snapshots) always carry this.
#.if ${ARCH} != "ia64" && ${ARCH} != "powerpc" && ${ARCH} != "sparc64"
INFO+=		gcc${SUFFIX}/libquadmath
#.endif

.if ${PORT_OPTIONS:MJAVA}
ECJ_JAR=	${LOCALBASE}/share/java/ecj-4.5.jar
BUILD_DEPENDS+=	${ECJ_JAR}:lang/gcc-ecj45 \
		zip:archivers/zip
RUN_DEPENDS+=	${ECJ_JAR}:lang/gcc-ecj45
EXTRA_PATCHES+=	${FILESDIR}/java-patch-hier
CONFIGURE_ARGS+=--with-ecj-jar=${ECJ_JAR}
LANGUAGES:=	${LANGUAGES},java
INFO+=		gcc${SUFFIX}/cp-tools \
		gcc${SUFFIX}/gcj
PLIST_SUB+=	JAVA=""
.else
CONFIGURE_ARGS+=--disable-libgcj
PLIST_SUB+=	JAVA="@comment "
.endif
CONFIGURE_ARGS+=--enable-languages=${LANGUAGES}

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION} for ${CONFIGURE_TARGET} [${LANGUAGES}]"

pre-configure:
	cd ${WRKSRC} ; contrib/gcc_update --touch
	@${RM} -f ${WRKSRC}/gcc/*/*.info*

.if defined(MAINTAINER_MODE)
full-regression-test: build
	cd ${TEST_WRKSRC}; ${MAKE_CMD} -sk check \
	; ${WRKSRC}/contrib/test_summary
.endif

post-stage:
	${RM} -f ${STAGEDIR}${PREFIX}/man/man7/*
	${RM} -f ${STAGEDIR}${PREFIX}/bin/rebuild-gcj-db${SUFFIX} \
	         ${STAGEDIR}${PREFIX}/man/man1/rebuild-gcj-db${SUFFIX}.1
	# Add target libraries and include files to packaging list.
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${TARGLIB:S/^${PREFIX}\///} ${LIBEXEC:S/^${PREFIX}\///} include/gcj include/gnu include/java include/javax
	cd ${STAGEDIR}${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
