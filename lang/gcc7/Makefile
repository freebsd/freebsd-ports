# Created by: Gerald Pfeifer <gerald@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	7.5.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	GCC
PKGNAMESUFFIX=	${SUFFIX}

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	GNU Compiler Collection 7

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

DEPRECATED=	Unsupported by upstream. Use GCC 9 or newer instead.
ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	runtest:misc/dejagnu
.endif

USES=		compiler cpe gmake iconv libtool makeinfo perl5 tar:xz
USE_BINUTILS=	yes
USE_PERL5=	build

CPE_VENDOR=	gnu

GCC_VERSION=	${PORTVERSION}
SUFFIX=		${PORTVERSION:C/([0-9]+).*/\1/}
CFLAGS:=	${CFLAGS:N-mretpoline}
CXXFLAGS:=	${CXXFLAGS:N-mretpoline}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.endif

LANGUAGES:=	c,c++
TARGLIB=	${PREFIX}/lib/gcc${SUFFIX}
TARGLIB32=	${PREFIX}/lib32	# The version information is added later
LIBEXEC=	${PREFIX}/libexec/gcc${SUFFIX}
GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ARGS+=--with-build-config=bootstrap-debug
ALL_TARGET=	bootstrap-lean
INSTALL_TARGET=	install-strip
.if ${UID} != 0
BINMODE=	755
.endif
CONFIGURE_ARGS+=--disable-nls \
		--disable-multilib \
		--enable-gnu-indirect-function \
		--enable-languages=${LANGUAGES} \
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
PLIST_SUB+=	GCC_VERSION=${GCC_VERSION} \
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
INFO+=		gcc${SUFFIX}/libquadmath \
		gcc${SUFFIX}/libitm
SUB_FILES=	pkg-message
SUB_LIST+=	TARGLIB=${TARGLIB}

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION} for ${CONFIGURE_TARGET} [${LANGUAGES}]"

pre-configure:
	cd ${WRKSRC} ; contrib/gcc_update --touch
	@${RM} ${WRKSRC}/gcc/*/*.info*

.if defined(MAINTAINER_MODE)
full-regression-test: build
	cd ${TEST_WRKSRC}; ${MAKE_CMD} -sk check \
	; ${WRKSRC}/contrib/test_summary
.endif

post-stage:
	${RM} ${STAGEDIR}${PREFIX}/man/man7/*
	${RM} -r ${STAGEDIR}${TARGLIB}/gcc/*/${GCC_VERSION}/include-fixed/
	# Add target libraries and include files to packaging list.
	${RM} ${WRKDIR}/PLIST.lib

.for d in ${TARGLIB:S/^${PREFIX}\///} ${TARGLIB32:S/^${PREFIX}\///} ${LIBEXEC:S/^${PREFIX}\///}
	cd ${STAGEDIR}${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
