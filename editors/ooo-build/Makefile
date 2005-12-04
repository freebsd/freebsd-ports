# New ports collection makefile for:	ooo-build
# Date created:			4 Dec 2005
# Whom:				Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ooo-build
PORTVERSION=	${OOO-BUILDVERSION}
MASTER_SITES+=	http://ooo.ximian.com/packages/OOO680/ \
		http://ooo.ximian.com/packages/SRC680/ \
		${MASTER_SITE_SOURCEFORGE:S/$/:wpd/}:wpd \
		http://www.openclipart.org/downloads/0.18/:openclipart
MASTER_SITE_SUBDIR+= libwpd/:wpd
DISTFILES+=	${OOOBUILD_SOURCE} ${OOO_CAIRO} \
	${OOO_MDBTOOLS} ${OOO_LIBWPD}:wpd \
	${OOO_EXTRA_ARTWORK} ${OOO_CRYSTAL_IMAGES} \
	${OOO_OPENCLIPART}:openclipart

MAINTAINER=	maho@FreeBSD.org

#DEVELOPER_VER=	yes #you must be an expert or guru to activate this 
.if defined(DEVELOPER_VER)
OOO-BUILDVERSION=2.0.0.${MILESTONE}
MILESTONE=	140
OOOBUILD=	ooo-build-src680.140.1
OOOBUILD_SOURCE=${OOOBUILD}.tar.gz
OOO_CAIRO=	cairo-1.0.2.tar.gz
OOO_MDBTOOLS=	mdbtools-0.6pre1.tar.gz
OOO_LIBWPD=	libwpd-0.8.3.tar.gz
OOO_EXTRA_ARTWORK=extras-2.tar.bz2
OOO_CRYSTAL_IMAGES=	ooo_crystal_images-6.tar.bz2
OOO_OPENCLIPART=	openclipart-0.18-full.tar.gz
OOO_PATCHDIR=src680
.else
OOO-BUILDVERSION=2.0.0.2
OOOBUILD=	ooo-build-${OOO-BUILDVERSION}
OOOBUILD_SOURCE=${OOOBUILD}.tar.gz
OOO_CAIRO=	cairo-1.0.2.tar.gz
OOO_MDBTOOLS=	mdbtools-0.6pre1.tar.gz
OOO_LIBWPD=	libwpd-0.8.3.tar.gz
OOO_EXTRA_ARTWORK=extras-2.tar.bz2
OOO_CRYSTAL_IMAGES=	ooo_crystal_images-6.tar.bz2
OOO_OPENCLIPART=	openclipart-0.18-full.tar.gz
OOO_PATCHDIR=OOO_2_0
.endif

MD5_FILE=      ${.CURDIR}/distinfo
USE_AUTOTOOLS=  autoconf:259

CONFIGURE_ARGS+= --with-icons="hicontrast industrial crystal"
#workarounds
CONFIGURE_ARGS+= --disable-access --disable-binfilter

INSTALLATION_BASEDIR=	ooo-build-${PORTVERSION}
EXECBASE=		ooo-build-${PORTVERSION}
DIST_SUBDIR=		openoffice.org2.0
SIMPLEOSVER=		${OSREL:C/\.//g}
PACKAGE_BASENAME=	ooo-build-${PORTVERSION}-${OPSYS}${SIMPLEOSVER}Intel

pre-configure:
#see ooo-build*/bin/unpack and others for details
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/${OOOBUILD_SOURCE} | ${TAR} xfz -
.if !defined(DEVELOPER_VER)
	@cd ${WRKDIR}/${OOOBUILD} ; ${PATCH} < ${.CURDIR}/files/ooo-build-patch
	@cd ${WRKDIR}/${OOOBUILD}/patches ; ${PERL} apply.pl ${WRKDIR}/${OOOBUILD}/patches/${OOO_PATCHDIR} ${WRKSRC} --distro=FreeBSD --distro=Binfilter
.else
	@cd ${WRKDIR}/${OOOBUILD} ; ${PATCH} < ${.CURDIR}/files/ooo-build-patch-devel
	@cd ${WRKDIR}/${OOOBUILD}/patches ; ${PERL} apply.pl ${WRKDIR}/${OOOBUILD}/patches/${OOO_PATCHDIR} ${WRKSRC} --distro=FreeBSD --distro=Binfilter --tag=src680-m${MILESTONE}
.endif
	@${MKDIR} ${WRKSRC}/cairo/download ; ${CP} ${DISTDIR}/${DIST_SUBDIR}/${OOO_CAIRO} ${WRKSRC}/cairo/download
	@${MKDIR} ${WRKSRC}/mdbtools/download ; ${CP} ${DISTDIR}/${DIST_SUBDIR}/${OOO_MDBTOOLS} ${WRKSRC}/mdbtools/download
	@${MKDIR} ${WRKSRC}/libwpd/download ; ${CP} ${DISTDIR}/${DIST_SUBDIR}/${OOO_LIBWPD} ${WRKSRC}/libwpd/download
	@${CP} ${WRKDIR}/${OOOBUILD}/src/evolocal.odb ${WRKSRC}/extras/source/database/
#extract some goodies
	cd ${WRKSRC} ; ${TAR} xjf ${DISTDIR}/${DIST_SUBDIR}/${OOO_EXTRA_ARTWORK}
	#cd ${WRKDIR} ; ${TAR} xjf ${DISTDIR}/${DIST_SUBDIR}/${OOO_OPENCLIPART}
#industrial set
	@cd ${WRKSRC}/ooo_custom_images/industrial/res/commandimagelist ; ${CP} -f lc_zoomplus.png lc_zoomin.png ; ${CP} -f sc_zoomplus.png sc_zoomin.png ; ${RM} -f ${WRKSRC}/extras/source/autotext/lang/en-US/acor_en-GB.*
	@${RM} -f ${WRKSRC}/ooo_custom_images/industrial/vcl/source/src/check*
	@${TAR} xjf ${DISTDIR}/${DIST_SUBDIR}/${OOO_CRYSTAL_IMAGES} -C ${WRKSRC}/ooo_custom_images

#apply FreeBSD specifc (?) patches for ooo-build :(
	@cd ${WRKSRC} ; ${PATCH} < ${.CURDIR}/files/cairo-patch
	@cd ${WRKSRC} ; ${PATCH} < ${.CURDIR}/files/patch-i18npool

.if defined(DEVELOPER_VER)
MASTERDIR=	${.CURDIR}/../openoffice.org-2.0-devel
.else
MASTERDIR=	${.CURDIR}/../openoffice.org-2.0
.endif

.include "${MASTERDIR}/Makefile"
