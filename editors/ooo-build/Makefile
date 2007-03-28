# New ports collection makefile for:	ooo-build
# Date created:			4 Dec 2005
# Whom:				Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ooo-build
PORTVERSION=	${OOOBUILD_VERSION}
MASTER_SITES+=	http://www.go-ooo.org/packages/OOE680/ \
		http://www.go-ooo.org/packages/SRC680/ \
		http://www.openclipart.org/downloads/0.18/:openclipart \
		${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/libwpd/g}:libwpd \
		http://go-oo.org/packages/SRC680/:libwps
DISTFILES+=	${OOOBUILD_SOURCE} \
	${OOO_EXTRA_ARTWORK} ${OOO_CRYSTAL_IMAGES} \
	${OOO_OPENCLIPART}:openclipart \
	${OOO_LIBWPD}:libwpd \
	${OOO_LIBWPS}:libwps

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Community enhanced/bug fixed version of OpenOffice.org

BROKEN=		new version of ooo-build is not yet available

DESCR=		${.CURDIR}/pkg-descr

#DEVELOPER_VER=	yes #you must be an expert or guru to activate this
.if defined(DEVELOPER_VER)
OOOBUILD_VERSION=2.0.2.${MILESTONE}
MILESTONE=	156
OOOBUILD_TAG=src680-m${MILESTONE}
OOOBUILD=	ooo-build-src680.${MILESTONE}.0
OOOBUILD_SOURCE=${OOOBUILD}.tar.gz
OOO_EXTRA_ARTWORK=extras-2.tar.bz2
OOO_CRYSTAL_IMAGES=	ooo_crystal_images-1.tar.gz
OOO_OPENCLIPART=	openclipart-0.18-full.tar.gz
OOO_PATCHDIR=src680
.else
OOOBUILD_VERSION=2.1.7
OOOBUILD_TAG=ooe680-m6
OOOSRC=		OOo_OOE680_m6_source.tar.bz2
OOOTAG=		OOE680_m6
OOOBUILD=	ooo-build-${OOOBUILD_VERSION}
#OOOBUILD=	ooo-build-${OOOBUILD_TAG}
OOOBUILD_SOURCE=${OOOBUILD}.tar.gz
OOO_EXTRA_ARTWORK=extras-2.tar.bz2
OOO_CRYSTAL_IMAGES=	ooo_crystal_images-1.tar.gz
OOO_OPENCLIPART=	openclipart-0.18-full.tar.gz
OOO_LIBWPD=		libwpd-0.8.8.tar.gz
OOO_LIBWPS=		libwps-0.1.0~svn20070129.tar.gz
OOO_PATCHDIR=src680
.endif

MD5_FILE=      ${.CURDIR}/distinfo
USE_AUTOTOOLS=  autoconf:259

CONFIGURE_ARGS+=	--enable-cairo --with-system-cairo
CONFIGURE_ARGS+=	--disable-access #--with-system-mdbtools
#for lpsolve...
CONFIGURE_ARGS+=	--with-system-lpsolve
CONFIGURE_ENV+=		CXXFLAGS="${CXXFLAGS} -L${PREFIX}/lib"
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -L${PREFIX}/lib"
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS} -I${PREFIX}/include"
LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo
LIB_DEPENDS+=	lpsolve55.1:${PORTSDIR}/math/lp_solve
#LIB_DEPENDS+=	mdb:${PORTSDIR}/databases/mdbtools
USE_GSTREAMER=	yes

INSTALLATION_BASEDIR=	ooo-build-${PORTVERSION}
EXECBASE=		ooo-build-${PORTVERSION}
DIST_SUBDIR=		openoffice.org2.0
SIMPLEOSVER=		${OSREL:C/\.//g}
PACKAGE_BASENAME=	ooo-build-${PORTVERSION}-${OPSYS}${SIMPLEOSVER}Intel

post-patch:
	#just for lpsolve...
	@cd ${WRKSRC}             ; ${PATCH} < ${.CURDIR}/files/set_soenv-patch

pre-configure:
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/${OOOBUILD_SOURCE} | ${TAR} xfz -
.if !defined(DEVELOPER_VER)
	@cd ${WRKDIR}/${OOOBUILD} ; ${PATCH} < ${.CURDIR}/files/ooo-build-patch
.else
	@cd ${WRKDIR}/${OOOBUILD} ; ${PATCH} < ${.CURDIR}/files/ooo-build-patch-devel
.endif
	@cd ${WRKDIR}/${OOOBUILD}/patches ; ${PERL} apply.pl ${WRKDIR}/${OOOBUILD}/patches/${OOO_PATCHDIR} ${WRKSRC} --distro=FreeBSD --distro=Binfilter --tag=${OOOBUILD_TAG}
	@${CP} ${WRKDIR}/${OOOBUILD}/src/evolocal.odb ${WRKSRC}/extras/source/database/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${OOO_LIBWPD} ${WRKSRC}/libwpd/download/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${OOO_LIBWPS} ${WRKSRC}/libwps/download/
.if !defined(DEVELOPER_VER)
	@${CP} ${WRKDIR}/${OOOBUILD}/src/go-oo-team.png ${WRKSRC}/default_images/sw/res
.endif
#extract some goodies
	cd ${WRKSRC} ; ${TAR} xjf ${DISTDIR}/${DIST_SUBDIR}/${OOO_EXTRA_ARTWORK}
	#cd ${WRKDIR} ; ${TAR} xjf ${DISTDIR}/${DIST_SUBDIR}/${OOO_OPENCLIPART}
.if defined(DEVELOPER_VER)
MASTERDIR=	${.CURDIR}/../openoffice.org-2-devel
.else
MASTERDIR=	${.CURDIR}/../openoffice.org-2
.endif

.include "${MASTERDIR}/Makefile"
