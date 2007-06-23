# New ports collection makefile for:	ooo-build
# Date created:			4 Dec 2005
# Whom:				Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ooo-build
PORTVERSION=	${OOOBUILD_VERSION}
MASTER_SITES+=	http://www.go-ooo.org/packages/OOF680/ \
		http://www.go-ooo.org/packages/SRC680/ \
		http://www.openclipart.org/downloads/0.18/:openclipart \
		${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/libwpd/g}:libwpd \
		http://go-oo.org/packages/SRC680/:libwps \
		http://go-oo.org/packages/SRC680/:libwpg
DISTFILES+=	${OOOBUILD_SOURCE} \
	${OOO_EXTRA_ARTWORK} ${OOO_CRYSTAL_IMAGES} \
	${OOO_OPENCLIPART}:openclipart \
	${OOO_LIBWPD}:libwpd \
	${OOO_LIBWPS}:libwps \
	${OOO_LIBWPG}:libwpg

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Community enhanced/bug fixed version of OpenOffice.org

DESCR=		${.CURDIR}/pkg-descr

OOOBUILD_VERSION=2.2.1
OOOBUILD_TAG=oof680-m18
OOOSRC=		OOo_OOF680_m18_source.tar.bz2
OOOTAG=		OOF680_m18
OOOBUILD=	ooo-build-${OOOBUILD_VERSION}
#OOOBUILD=	ooo-build-${OOOBUILD_TAG}
OOOBUILD_SOURCE=${OOOBUILD}.tar.gz
OOO_EXTRA_ARTWORK=extras-2.tar.bz2
OOO_CRYSTAL_IMAGES=	ooo_crystal_images-1.tar.gz
OOO_OPENCLIPART=	openclipart-0.18-full.tar.gz
OOO_LIBWPD=		libwpd-0.8.10.tar.gz
OOO_LIBWPS=		libwps-0.1.0~svn20070129.tar.gz
OOO_LIBWPG=		libwpg-0.1.0~cvs20070608.tar.gz
OOO_PATCHDIR=src680

MD5_FILE=      ${.CURDIR}/distinfo
USE_AUTOTOOLS=  autoconf:259

CONFIGURE_ARGS+=	--enable-cairo
CONFIGURE_ARGS+=	--with-system-xrender-headers
CONFIGURE_ARGS+=	--disable-access #--with-system-mdbtools
CONFIGURE_ARGS+=	--enable-vba --with-vba-package-format="builtin"
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
	@cd ${WRKDIR}/${OOOBUILD} ; ${PATCH} < ${.CURDIR}/files/ooo-build-patch
	@cd ${WRKDIR}/${OOOBUILD}/patches ; ${PERL} apply.pl ${WRKDIR}/${OOOBUILD}/patches/${OOO_PATCHDIR} ${WRKSRC} --distro=FreeBSD --distro=Binfilter --tag=${OOOBUILD_TAG}
	@${CP} ${WRKDIR}/${OOOBUILD}/src/evolocal.odb ${WRKSRC}/extras/source/database/
	@${CP} ${WRKDIR}/${OOOBUILD}/src/go-oo-team.png ${WRKSRC}/default_images/sw/res/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${OOO_LIBWPD} ${WRKSRC}/libwpd/download/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${OOO_LIBWPS} ${WRKSRC}/libwps/download/
	@${MKDIR} ${WRKSRC}/libwpg/download/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${OOO_LIBWPG} ${WRKSRC}/libwpg/download/
#extract some goodies
	cd ${WRKSRC} ; ${TAR} xjf ${DISTDIR}/${DIST_SUBDIR}/${OOO_EXTRA_ARTWORK}
	#cd ${WRKDIR} ; ${TAR} xjf ${DISTDIR}/${DIST_SUBDIR}/${OOO_OPENCLIPART}
MASTERDIR=	${.CURDIR}/../openoffice.org-2

.include "${MASTERDIR}/Makefile"
