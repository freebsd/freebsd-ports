# Created by: dwm
# $FreeBSD$

PORTNAME=	icu
PORTVERSION=	50.1.2
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
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

GNU_CONFIGURE=		yes
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


USES=			gmake pathfix
INSTALL_TARGET=		install install-manx

ICUMAJOR=	${PORTVERSION:C/\..*//}
PLIST_SUB+=	ICUMAJOR=${ICUMAJOR} ICUVER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not compile on arm
.endif

.if ${PORT_OPTIONS:MTHREADS}
# This builds thread-safe, but not the thread-using version:
CONFIGURE_ARGS+=	--enable-weak-threads
.else
CONFIGURE_ARGS+=	--enable-threads=no
.endif

post-patch:
	@${REINPLACE_CMD} -e '/CXXFLAGS=/s/-ansi//' \
		${WRKSRC}/configure
.if ! ${PORT_OPTIONS:MTHREADS}
	@${REINPLACE_CMD} -e 's,\(THREADSC.*FLAGS\).*,\1=,g' ${WRKSRC}/config/mh-bsd-gcc
.endif

iotest cintltst intltest:
	# Performing the ${.TARGET} test
	-${GMAKE} -C ${WRKSRC}/test
	cd ${WRKSRC}/test/${.TARGET} && ${SETENV} \
	    LD_LIBRARY_PATH=${WRKSRC}/lib:${WRKSRC}/tools/ctestfw \
	    ./${.TARGET}

test regression-test: iotest cintltst intltest

.include <bsd.port.post.mk>
