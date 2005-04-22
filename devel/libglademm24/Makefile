# New ports collection makefile for:    libglademm
# Date created:         22 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	libglademm
PORTVERSION=	2.6.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libglade2 library

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

LATEST_LINK=	libglademm24

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GCC=	3.4
USE_REINPLACE=  yes
USE_GNOME=	gnomehack libglade2
USE_INC_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

PLIST_SUB=	VERSION="2.4" API_VERSION="2.4"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS = .*\)\(docs\)\(.*\)|\1\3|' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e "s|\(-lglibmm\)|-L\$$(GMM_PROCDIR)/../.. \1|" \
		${WRKSRC}/tools/extra_defs_gen/Makefile.in

patch-autotools:
	@(cd ${PATCH_WRKSRC}; \
	for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "/^ltmain=/s^\$$ac_aux_dir/ltmain.sh^${LTMAIN}^g" \
			$$file.tmp > $$file; \
		${RM} $$file.tmp; \
	done);

.include <bsd.port.mk>
