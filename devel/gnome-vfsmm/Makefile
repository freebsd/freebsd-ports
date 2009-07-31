# New ports collection makefile for:    gnome-vfsmm
# Date created:         22 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD$
#   $MCom: ports/devel/gnome-vfsmm/Makefile,v 1.31 2009/03/17 15:22:21 kwm Exp $
#

PORTNAME=	gnome-vfsmm
PORTVERSION=	2.26.0
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for gnomevfs2 library

LIB_DEPENDS=	glibmm-2.4.1:${PORTSDIR}/devel/glibmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomevfs2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples// ; \
	    	/^SUBDIRS =/s/docs//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|\(-lglibmm\)|-L\$$(GMM_PROCDIR)/../.. \1|" \
		${WRKSRC}/tools/extra_defs_gen/Makefile.in

.include <bsd.port.mk>
