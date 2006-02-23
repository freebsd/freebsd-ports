# New ports collection makefile for:    libglademm
# Date created:         22 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD$
#   $MCom: ports/devel/libglademm24/Makefile,v 1.5 2005/10/14 20:39:56 adamw Exp $
#

PORTNAME=	libglademm
PORTVERSION=	2.6.1
PORTREVISION=	1
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
GNU_CONFIGURE=	yes
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

.include <bsd.port.mk>
