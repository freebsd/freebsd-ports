# New ports collection makefile for:	ooo-build
# Date created:			4 Dec 2005
# Whom:				Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ooo-build
PORTVERSION=	${OOOBUILD_VERSION}
MASTER_SITES+=	http://ooo.ximian.com/packages/OOB680/ \
		http://ooo.ximian.com/packages/SRC680/ \
		http://www.openclipart.org/downloads/0.18/:openclipart
DISTFILES+=	${OOOBUILD_SOURCE} \
	${OOO_EXTRA_ARTWORK} ${OOO_CRYSTAL_IMAGES} \
	${OOO_OPENCLIPART}:openclipart

MAINTAINER=	maho@FreeBSD.org

COMMENT=	Community enhanced/bug fixed version of OpenOffice.org

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
OOOBUILD_VERSION=2.0.2.9
OOOBUILD_TAG=oob680-m5
OOOBUILD=	ooo-build-${OOOBUILD_VERSION}
OOOBUILD_SOURCE=${OOOBUILD}.tar.gz
OOO_EXTRA_ARTWORK=extras-2.tar.bz2
OOO_CRYSTAL_IMAGES=	ooo_crystal_images-1.tar.gz
OOO_OPENCLIPART=	openclipart-0.18-full.tar.gz
OOO_PATCHDIR=src680
.endif

MD5_FILE=      ${.CURDIR}/distinfo
USE_AUTOTOOLS=  autoconf:259

CONFIGURE_ARGS+=	--with-system-cairo --disable-access #--with-system-mdbtools
LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo
#LIB_DEPENDS+=	mdb:${PORTSDIR}/databases/mdbtools

INSTALLATION_BASEDIR=	ooo-build-${PORTVERSION}
EXECBASE=		ooo-build-${PORTVERSION}
DIST_SUBDIR=		openoffice.org2.0
SIMPLEOSVER=		${OSREL:C/\.//g}
PACKAGE_BASENAME=	ooo-build-${PORTVERSION}-${OPSYS}${SIMPLEOSVER}Intel

pre-configure:
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/${OOOBUILD_SOURCE} | ${TAR} xfz -
.if !defined(DEVELOPER_VER)
	@cd ${WRKDIR}/${OOOBUILD} ; ${PATCH} < ${.CURDIR}/files/ooo-build-patch
	#@${REINPLACE_CMD} -e 's|== "|= "|g'	${WRKDIR}/${OOOBUILD}/patches/src680/disable-access.diff
.else
	@cd ${WRKDIR}/${OOOBUILD} ; ${PATCH} < ${.CURDIR}/files/ooo-build-patch-devel
.endif
	@cd ${WRKDIR}/${OOOBUILD}/patches ; ${PERL} apply.pl ${WRKDIR}/${OOOBUILD}/patches/${OOO_PATCHDIR} ${WRKSRC} --distro=FreeBSD --distro=Binfilter --tag=${OOOBUILD_TAG}
	@${CP} ${WRKDIR}/${OOOBUILD}/src/evolocal.odb ${WRKSRC}/extras/source/database/
.if !defined(DEVELOPER_VER)
	@${CP} ${WRKDIR}/${OOOBUILD}/src/go-oo-team.png ${WRKSRC}/default_images/sw/res
.endif
#extract some goodies
	cd ${WRKSRC} ; ${TAR} xjf ${DISTDIR}/${DIST_SUBDIR}/${OOO_EXTRA_ARTWORK}
	#cd ${WRKDIR} ; ${TAR} xjf ${DISTDIR}/${DIST_SUBDIR}/${OOO_OPENCLIPART}
.if defined(DEVELOPER_VER)
	@${MKDIR} ${WRKSRC}/external_images
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${OOO_CRYSTAL_IMAGES} ${WRKSRC}/external_images
.endif

.if defined(DEVELOPER_VER)
MASTERDIR=	${.CURDIR}/../openoffice.org-2.0-devel
.else
MASTERDIR=	${.CURDIR}/../openoffice.org-2.0
.endif

.include "${MASTERDIR}/Makefile"
