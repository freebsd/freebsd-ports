# New ports collection makefile for:	icu
# Date created:				22 Jan 2001
# Whom:					dwm
#
# $FreeBSD$
#

PORTNAME=	icu2
PORTVERSION=	2.8
CATEGORIES=	devel
MASTER_SITES=	ftp://www-126.ibm.com/pub/icu/${PORTVERSION}/
DISTNAME=	icu-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	International Components for Unicode

CONFLICTS=	icu-[0-9]*

INSTALLS_SHLIB=		yes
NO_FILTER_SHLIBS=	yes

WRKSRC=			${WRKDIR}/icu
ICUWRKSRC=		${WRKSRC}/source
CONFIGURE_WRKSRC=	${ICUWRKSRC}
BUILD_WRKSRC=		${ICUWRKSRC}
INSTALL_WRKSRC=		${ICUWRKSRC}

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	runConfigureICU
CONFIGURE_ARGS+=	FreeBSD
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--enable-samples=no --enable-tests=no
.if defined(NO_THREADS)
CONFIGURE_ARGS+=	--enable-threads=no
.else
CONFIGURE_ENV+=		THREADSCPPFLAGS="${PTHREAD_CFLAGS}" \
			THREADSCFLAGS="${PTHREAD_CFLAGS}" \
			THREADSCXXFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"
.endif
CONFIGURE_ENV+=		CXXFLAGS="-O3"
CONFIGURE_ENV+=		CFLAGS="-O3"
USE_GMAKE=		yes

MAN1+=	gencnval.1
MAN1+=	genrb.1
MAN1+=	icu-config.1
MAN1+=	makeconv.1
MAN1+=	pkgdata.1
MAN1+=	uconv.1
MAN5+=	convrtrs.txt.5
MAN8+=	decmn.8
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

pre-fetch:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${ECHO} ''
	@${ECHO} 'You may use the following build options by defining'
	@${ECHO} 'them on the command line with -D'
	@${ECHO} ''
	@${ECHO} 'NO_THREADS	do not build a thread enabled library'
	@${ECHO} ''
	@/bin/sleep 2
.endif

.include <bsd.port.mk>
