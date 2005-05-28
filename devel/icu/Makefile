# New ports collection makefile for:	icu
# Date created:				22 Jan 2001
# Whom:					dwm
#
# $FreeBSD$
#

PORTNAME=	icu
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.software.ibm.com/software/globalization/icu/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	International Components for Unicode (from IBM)

CONFLICTS=	icu2-[0-9]*

INSTALLS_SHLIB=		yes
NO_FILTER_SHLIBS=	yes

WRKSRC=			${WRKDIR}/icu
ICUWRKSRC=		${WRKSRC}/source
CONFIGURE_WRKSRC=	${ICUWRKSRC}
BUILD_WRKSRC=		${ICUWRKSRC}
INSTALL_WRKSRC=		${ICUWRKSRC}

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	runConfigureICU
CONFIGURE_ARGS+=	${OPSYS}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--enable-samples=no --enable-tests=yes
.if defined(NO_THREADS)
CONFIGURE_ARGS+=	--enable-threads=no
.else
CONFIGURE_ENV+=		THREADSCPPFLAGS="${PTHREAD_CFLAGS}" \
			THREADSCFLAGS="${PTHREAD_CFLAGS}" \
			THREADSCXXFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"
.endif
USE_GMAKE=		yes
CONFIGURE_ENV+=		CFLAGS="${CFLAGS}" CC="${CC}" CXX="${CXX}"

MAN1+=	derb.1
MAN1+=	gencnval.1
MAN1+=	genrb.1
MAN1+=	icu-config.1
MAN1+=	makeconv.1
MAN1+=	pkgdata.1
MAN1+=	uconv.1
MAN8+=	decmn.8
MAN8+=	gencase.8
MAN8+=	genccode.8
MAN8+=	gencmn.8
MAN8+=	gennames.8
MAN8+=	gennorm.8
MAN8+=	genprops.8
MAN8+=	gensprep.8
MAN8+=	genuca.8

ICUMAJOR=	${PORTVERSION:S/.//:R}
PLIST_SUB+=	ICUMAJOR=${ICUMAJOR}
PLIST_SUB+=	ICUVER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Floating point exception during build on alpha"
.endif

pre-fetch:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	#
	# You may use the following build options by defining
	# them on the command line with -D
	#
	# NO_THREADS	do not build a thread enabled library
	#
.endif

pre-patch:
# VPATH does not work due to IBM's mistake:
	${LN} -s ${FILESDIR}/*.ucm ${WRKSRC}/source/data/mappings/
	@for l in ${FILESDIR}/*.ucm ; do \
		${ECHO} UCM_SOURCE_LOCAL+=`basename $$l` >> \
		    ${WRKSRC}/source/data/mappings/ucmlocal.mk ; \
	done

iotest cintltst intltest:
	-${GMAKE} -C ${ICUWRKSRC}/test
	cd ${ICUWRKSRC}/test/${.TARGET} && ${SETENV} \
	    LD_LIBRARY_PATH=${ICUWRKSRC}/lib:${ICUWRKSRC}/tools/ctestfw \
	    ./${.TARGET}

test: iotest cintltst intltest

post-build: iotest cintltst
	#
	# Note, due to occasional hangs in one of the intltest's
	# multi-threading subtests, the intltest is not part of automatic
	# test in the current version of this port. This an unresolved
	# problem so far:
	#	http://www.jtcsv.com/cgibin/icu-bugs/incoming?id=1141
	#
	# If you wish to help resolving it, try
	#
	#	`make intltest' manually.
	#

.include <bsd.port.post.mk>
