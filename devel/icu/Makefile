# New ports collection makefile for:	icu
# Date created:				22 Jan 2001
# Whom:					dwm
#
# $FreeBSD$
#

PORTNAME=	icu
PORTVERSION=	4.6.1

CATEGORIES=	devel
MASTER_SITES=	http://download.icu-project.org/files/icu4c/${PORTVERSION}/
DISTNAME=	icu4c-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	International Components for Unicode (from IBM)

OPTIONS=	THREADS "Build thread-safe version of the library" on

USE_LDCONFIG=		yes

WRKSRC=			${WRKDIR}/icu/source

LICENSE=	ICU
LICENSE_NAME=	ICU license
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}
LICENSE_FILE=	${WRKSRC}/../unicode-license.txt

CONFLICTS=	icu2-[0-9]* icu-4.4*

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	runConfigureICU
CONFIGURE_ARGS+=	${OPSYS}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--enable-samples=no
CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man
MAKE_JOBS_UNSAFE=	yes

USE_GMAKE=		yes
INSTALL_TARGET=		install install-manx

MAN1+=	derb.1
MAN1+=	genbrk.1
MAN1+=	gencnval.1
MAN1+=	genctd.1
MAN1+=	genrb.1
MAN1+=	icu-config.1
MAN1+=	makeconv.1
MAN1+=	pkgdata.1
MAN1+=	uconv.1
MAN8+=	icupkg.8
MAN8+=	genccode.8
MAN8+=	gencmn.8
MAN8+=	gensprep.8

ICUMAJOR=	${PORTVERSION:S/.//:R}
ICUMINOR=	${PORTVERSION:S/.//:E}
.if ${ICUMINOR} == ""
ICUMINOR=	0
.endif
PLIST_SUB+=	ICUMAJOR=${ICUMAJOR} ICUMINOR=${ICUMINOR} ICUVER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--enable-threads=no
.else
# This builds thread-safe, but not the thread-using version:
CONFIGURE_ARGS+=	--enable-weak-threads
.endif

post-patch:
.if defined(WITHOUT_THREADS)
	@${REINPLACE_CMD} -e 's,\(THREADSC.*FLAGS\).*,\1=${PTHREAD_CFLAGS},g' ${WRKSRC}/config/mh-bsd-gcc
.endif
	@${REINPLACE_CMD} -e 's,$$(libdir)/pkgconfig,${PREFIX}/libdata/pkgconfig,g' ${WRKSRC}/Makefile.in

iotest cintltst intltest:
	# Performing the ${.TARGET} test
	-${GMAKE} -C ${WRKSRC}/test
	cd ${WRKSRC}/test/${.TARGET} && ${SETENV} \
	    LD_LIBRARY_PATH=${WRKSRC}/lib:${WRKSRC}/tools/ctestfw \
	    ./${.TARGET}

post-build test regression-test: iotest cintltst intltest

.include <bsd.port.post.mk>
