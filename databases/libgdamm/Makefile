# New ports collection makefile for:    libglademm
# Date created:         1 Oct 2003
# Whom:                 Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgdamm
PORTVERSION=	1.3.6
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.3
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgda2 library

LIB_DEPENDS=	glibmm-2.4:${PORTSDIR}/devel/glibmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GCC=	3.4
USE_GMAKE=	yes
USE_GNOME=	gnomehack libgda2
USE_INC_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

patch-autotools:
	@(cd ${PATCH_WRKSRC}; \
	for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "/^ltmain=/s^\$$ac_aux_dir/ltmain.sh^${LTMAIN}^g" \
		$$file.tmp > $$file; \
		${RM} $$file.tmp; \
	done);

.include <bsd.port.mk>
