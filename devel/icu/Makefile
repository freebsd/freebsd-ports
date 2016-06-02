# Created by: dwm
# $FreeBSD$

PORTNAME=	icu
PORTVERSION=	55.1
CATEGORIES=	devel
MASTER_SITES=	http://download.icu-project.org/files/icu4c/${PORTVERSION}/ \
		SF/${PORTNAME}/ICU4C/${PORTVERSION}/
DISTNAME=	icu4c-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	office@FreeBSD.org
COMMENT=	International Components for Unicode (from IBM)

LICENSE=	ICU
LICENSE_NAME=	ICU license
LICENSE_FILE=	${WRKSRC}/../license.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=	THREADS
OPTIONS_DEFAULT=	THREADS
THREADS_DESC=	Build thread-safe version of the library

USE_LDCONFIG=		yes

WRKSRC=			${WRKDIR}/icu/source

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-data-packaging=library \
			--disable-samples \
			--enable-release \
			--enable-shared \
			--enable-static

.if defined(X_BUILD_FOR)
CONFIGURE_ARGS+=	--with-cross-build
.endif


USES=			gmake pathfix

ICUMAJOR=	${PORTVERSION:C/\..*//}
PLIST_SUB+=	ICUMAJOR=${ICUMAJOR} ICUVER=${PORTVERSION}

# This builds thread-safe, but not the thread-using version:
THREADS_CONFIGURE_ON=	--enable-weak-threads
THREADS_CONFIGURE_OFF=	--enable-threads=no

.include <bsd.port.options.mk>

# For all Bigendian systems, set CPPFLAGS so that icu compiles and checks correctly
.if ${ARCH} == "mips" || ${ARCH} == "mips64" || ${ARCH} == "sparc64" || ${ARCH} == "powerpc" || ${ARCH} == "powerpc64"
CPPFLAGS+=	-DU_IS_BIG_ENDIAN=1
.endif

post-patch:
	@${REINPLACE_CMD} -e '/CXXFLAGS=/s/-ansi//' \
		${WRKSRC}/configure
.if ! ${PORT_OPTIONS:MTHREADS}
	@${REINPLACE_CMD} -e 's,\(THREADSC.*FLAGS\).*,\1=,g' ${WRKSRC}/config/mh-bsd-gcc
.endif

iotest cintltst intltest:
	# Performing the ${.TARGET} test
	-${MAKE_CMD} -C ${WRKSRC}/test
	cd ${WRKSRC}/test/${.TARGET} && ${SETENV} \
	    LD_LIBRARY_PATH=${WRKSRC}/lib:${WRKSRC}/tools/ctestfw \
	    ./${.TARGET}

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/g* \
		${STAGEDIR}${PREFIX}/bin/*conv \
		${STAGEDIR}${PREFIX}/bin/icuinfo \
		${STAGEDIR}${PREFIX}/bin/derb \
		${STAGEDIR}${PREFIX}/bin/pkgdata
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libicuda*.so.*

test regression-test: iotest cintltst intltest

.include <bsd.port.mk>
